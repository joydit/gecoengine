#include "gtest/gtest.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
/**
 *  unit tests have:
 *  1) TEST(GECO_ENGINE_ULTILS, TEST_WHEEL_TIMER_BIT_OPS)
 *
 */

#include "common/ultils/geco-engine-ultils.h"
using namespace geco::ultils;
static int naive_clz(int bits, uint64_t v)
{
    int r = 0;
    uint64_t bit = ((uint64_t) 1) << (bits - 1);
    while (bit && 0 == (v & bit))
    {
        r++;
        bit >>= 1;
    }
    return r;
}
static int naive_ctz(int bits, uint64_t v)
{
    int r = 0;
    uint64_t bit = 1;
    while (bit && 0 == (v & bit))
    {
        r++;
        bit <<= 1;
        if (r == bits)
            break;
    }
    return r;
}
static int check(uint64_t vv)
{
    uint32_t v32 = (uint32_t) vv;
    if (vv == 0)
    {
        return 1; /* c[tl]z64(0) is undefined. */
    }

    if (ctz64(vv) != naive_ctz(64, vv))
    {
        printf("mismatch with %d ctz64: %d, naive_ctz: %d\n", vv, ctz64(vv),
                naive_ctz(64, vv));
        exit(1);
        return 0;
    }
    if (clz64(vv) != naive_clz(64, vv))
    {
        printf("mismatch with %d clz64: %d, %d\n", vv, clz64(vv),
                naive_clz(64, vv));
        exit(1);
        return 0;
    }

    if (v32 == 0)
        return 1; /* c[lt]z(0) is undefined. */

    if (ctz32(v32) != naive_ctz(32, v32))
    {
        printf("mismatch with ctz32: %d\n", ctz32(v32));
        exit(1);
        return 0;
    }
    if (clz32(v32) != naive_clz(32, v32))
    {
        printf("mismatch with clz32: %d\n", clz32(v32));
        exit(1);
        return 0;
    }
    return 1;
}
TEST(GECO_ENGINE_ULTILS, TEST_WHEEL_TIMER_BIT_OPS)
{
    uint64_t testcases[] = { 13371337 * 10, 100, 385789752, 82574,
            (((uint64_t) 1) << 63) + (((uint64_t) 1) << 31) + 10101 };

    unsigned int i;
    const unsigned int n = sizeof(testcases) / sizeof(testcases[0]);
    int result = 0;

    for (i = 0; i <= 63; ++i)
    {
        uint64_t x = 1 << i;
        if (!check(x))
            result = 1;
        --x;
        if (!check(x))
            result = 1;
    }
    for (i = 0; i < n; ++i)
    {
        if (!check(testcases[i]))
            result = 1;
    }
    EXPECT_EQ(result, 0);
}

#include "common/ultils/geco-ds-wheel-timer.h"
static int& test_bind(int& timer_type)
{
    int* a = new int;
    *a = 1;
    return *a;
}
static int* test_bind2(int* timer_type)
{
    int* a = new int;
    *a = 1;
    return a;
}
typedef int& (*fn1)(int&); // cannot put fn1 to typedef function not typed !
typedef std::function<int&(int&)> mycb;
typedef std::function<int*(int*)> mycb2;
using namespace std::placeholders;
// adds visibility of _1, _2, _3,...
TEST(GECO_ENGINE_ULTILS, TEST_WHEEL_TIMER_CB)
{
    mycb f = std::bind(test_bind, _1);
    int a = 1;
    int& ret = f(a);
    EXPECT_EQ(1, ret);
    delete &ret;

    mycb2 f2 = std::bind(test_bind2, _1);
    int* ret2 = f2(&a);
    EXPECT_EQ(1, *ret2);
    delete ret2;

}

#include "common/ultils/geco-ds-wheel-timer.h"
using namespace geco::ultils;
#define THE_END_OF_TIME ((time_t)-1)
#define FAIL() do {printf("Failure on line %d\n", __LINE__);	goto done;} while (0)
/* configuration for check_randomized */
struct rand_cfg
{
        /* When creating timeouts, smallest possible delay */
        time_t min_timeout;
        /* When creating timeouts, largest possible delay */
        time_t max_timeout;
        /* First time to start the clock at. */
        time_t start_at;
        /* Do not advance the clock past this time. */
        time_t end_at;
        /* Number of timeouts to create and monitor. */
        int n_timeouts;
        /* Advance the clock by no more than this each step. */
        time_t max_step;
        /* Use relative timers and stepping */
        int relative;
        /* Every time the clock ticks, try removing this many timeouts at
         * random. */
        int try_removing;
        /* When we're done, advance the clock to the end of time. */
        int finalize;
};
/* Not very random */
static time_t random_to(time_t min, time_t max)
{
    if (max <= min)
        return min;
    /* Not actually all that random, but should exercise the code. */
    time_t rand64 = rand() * (time_t) INT_MAX + rand();
    return min + (rand64 % (max - min));
}
static int check_randomized(const struct rand_cfg *cfg)
{
    int i, err;
    int rv = 1;
    wtimer_t* t = new wtimer_t[cfg->n_timeouts];
    time_t* timeouts = new time_t[cfg->n_timeouts];
    uint8_t *fired = new uint8_t[cfg->n_timeouts];
    uint8_t *found = new uint8_t[cfg->n_timeouts];
    uint8_t *deleted = new uint8_t[cfg->n_timeouts];

    //check open
    wtimers_t tos;
    tos.open(TIMEOUT_mHZ);
    EXPECT_EQ(tos.get_hz(), TIMEOUT_mHZ);
    EXPECT_EQ(tos.curtime, 0);
    for (int i = 0; i < WHEEL_NUM; i++)
    {
        EXPECT_EQ(tos.pending[i], 0);
    }

    time_t now = cfg->start_at;
    int n_added_pending = 0, cnt_added_pending = 0;
    int n_added_expired = 0, cnt_added_expired = 0;
    wtimer_iterator_t it_p, it_e, it_all;
    int p_done = 0, e_done = 0, all_done = 0;
    wtimer_t *to = NULL;
    const int rel = cfg->relative;

    EXPECT_EQ(!t || !timeouts || !fired || !found || !deleted, false);

    tos.update(cfg->start_at);
    for (i = 0; i < cfg->n_timeouts; ++i)
    {
        t[i].init(rel ? 0 : ABS_TIMEOUT);
        EXPECT_EQ(t[i].pending_wheel(), false);
        EXPECT_EQ(t[i].pending_expired(), false);

        timeouts[i] = random_to(cfg->min_timeout, cfg->max_timeout);
        tos.add_timer(t + i, timeouts[i] - (rel ? now : 0));
        if (timeouts[i] <= cfg->start_at)
        {
            EXPECT_EQ(t[i].pending_wheel(), false);
            EXPECT_EQ(t[i].pending_expired(), true);
            ++n_added_expired;
        }
        else
        {
            EXPECT_EQ(t[i].pending_wheel(), true);
            EXPECT_EQ(t[i].pending_expired(), false);
            ++n_added_pending;
        }
    }

    EXPECT_EQ(!!n_added_pending, tos.has_expiring_timer());
    EXPECT_EQ(!!n_added_expired, tos.has_expired_timer());

    while (NULL != (to = tos.get_expired_timer()))
    {
        i = to - &t[0];
        EXPECT_EQ(&t[i], to);
        EXPECT_GE(cfg->start_at,timeouts[i]);/* shouldn't have happened yet */
        --n_added_expired; /* drop expired timeouts. */
        ++fired[i];
    }
    EXPECT_EQ(n_added_expired, 0);

}

TEST(GECO_ENGINE_ULTILS, TEST_WHEEL_TIMER)
{
    rand_cfg
    cfg1 =
    {
        .min_timeout = 1,
        .max_timeout = 100,
        .start_at = 5,
        .end_at = 1000,
        .n_timeouts = 1000,
        .max_step = 10,
        .relative = 0,
        .try_removing = 0,
        .finalize = 2,
    };
    check_randomized (&cfg1);
}

