#include "test/jemalloc_test.h"

TEST_BEGIN(test_pow2_ceil)
{
	unsigned i, pow2;
	size_t x;

	assert_zu_eq(pow2_ceil(0), 0, "Unexpected result");

	for (i = 0; i < sizeof(size_t) * 8; i++) {
		assert_zu_eq(pow2_ceil(ZU(1) << i), ZU(1) << i,
		    "Unexpected result");
	}

	for (i = 2; i < sizeof(size_t) * 8; i++) {
		assert_zu_eq(pow2_ceil((ZU(1) << i) - 1), ZU(1) << i,
		    "Unexpected result");
	}

	for (i = 0; i < sizeof(size_t) * 8 - 1; i++) {
		assert_zu_eq(pow2_ceil((ZU(1) << i) + 1), ZU(1) << (i+1),
		    "Unexpected result");
	}

	for (pow2 = 1; pow2 < 25; pow2++) {
		for (x = (ZU(1) << (pow2-1)) + 1; x <= ZU(1) << pow2; x++) {
			assert_zu_eq(pow2_ceil(x), ZU(1) << pow2,
			    "Unexpected result, x=%zu", x);
		}
	}
}
TEST_END

TEST_BEGIN(test_malloc_strtoumax_no_endptr)
{
	int err;

	set_errno(0);
	assert_ju_eq(malloc_strtoumax("0", NULL, 0), 0, "Unexpected result");
	err = get_errno();
	assert_d_eq(err, 0, "Unexpected failure");
}
TEST_END

TEST_BEGIN(test_malloc_strtoumax)
{
	struct test_s {
		const char *input;
		const char *expected_remainder;
		int base;
		int expected_errno;
		const char *expected_errno_name;
		uintmax_t expected_x;
	};
#define	ERR(e)	e, #e
#define	UMAX(x)	((uintmax_t)x##ULL)
	struct test_s tests[] = {
		{"0",		"0",	-1,	ERR(EINVAL),	UINTMAX_MAX},
		{"0",		"0",	1,	ERR(EINVAL),	UINTMAX_MAX},
		{"0",		"0",	37,	ERR(EINVAL),	UINTMAX_MAX},

		{"",		"",	0,	ERR(EINVAL),	UINTMAX_MAX},
		{"+",		"+",	0,	ERR(EINVAL),	UINTMAX_MAX},
		{"++3",		"++3",	0,	ERR(EINVAL),	UINTMAX_MAX},
		{"-",		"-",	0,	ERR(EINVAL),	UINTMAX_MAX},

		{"42",		"",	0,	ERR(0),		UMAX(42)},
		{"+42",		"",	0,	ERR(0),		UMAX(42)},
		{"-42",		"",	0,	ERR(0),		UMAX(-42)},
		{"042",		"",	0,	ERR(0),		UMAX(042)},
		{"+042",	"",	0,	ERR(0),		UMAX(042)},
		{"-042",	"",	0,	ERR(0),		UMAX(-042)},
		{"0x42",	"",	0,	ERR(0),		UMAX(0x42)},
		{"+0x42",	"",	0,	ERR(0),		UMAX(0x42)},
		{"-0x42",	"",	0,	ERR(0),		UMAX(-0x42)},

		{"0",		"",	0,	ERR(0),		UMAX(0)},
		{"1",		"",	0,	ERR(0),		UMAX(1)},

		{"42",		"",	0,	ERR(0),		UMAX(42)},
		{" 42",		"",	0,	ERR(0),		UMAX(42)},
		{"42 ",		" ",	0,	ERR(0),		UMAX(42)},
		{"0x",		"x",	0,	ERR(0),		UMAX(0)},
		{"42x",		"x",	0,	ERR(0),		UMAX(42)},

		{"07",		"",	0,	ERR(0),		UMAX(7)},
		{"010",		"",	0,	ERR(0),		UMAX(8)},
		{"08",		"8",	0,	ERR(0),		UMAX(0)},
		{"0_",		"_",	0,	ERR(0),		UMAX(0)},

		{"0x",		"x",	0,	ERR(0),		UMAX(0)},
		{"0X",		"X",	0,	ERR(0),		UMAX(0)},
		{"0xg",		"xg",	0,	ERR(0),		UMAX(0)},
		{"0XA",		"",	0,	ERR(0),		UMAX(10)},

		{"010",		"",	10,	ERR(0),		UMAX(10)},
		{"0x3",		"x3",	10,	ERR(0),		UMAX(0)},

		{"12",		"2",	2,	ERR(0),		UMAX(1)},
		{"78",		"8",	8,	ERR(0),		UMAX(7)},
		{"9a",		"a",	10,	ERR(0),		UMAX(9)},
		{"9A",		"A",	10,	ERR(0),		UMAX(9)},
		{"fg",		"g",	16,	ERR(0),		UMAX(15)},
		{"FG",		"G",	16,	ERR(0),		UMAX(15)},
		{"0xfg",	"g",	16,	ERR(0),		UMAX(15)},
		{"0XFG",	"G",	16,	ERR(0),		UMAX(15)},
		{"z_",		"_",	36,	ERR(0),		UMAX(35)},
		{"Z_",		"_",	36,	ERR(0),		UMAX(35)}
	};
#undef ERR
#undef UMAX
	unsigned i;

	for (i = 0; i < sizeof(tests)/sizeof(struct test_s); i++) {
		struct test_s *test = &tests[i];
		int err;
		uintmax_t result;
		char *remainder;

		set_errno(0);
		result = malloc_strtoumax(test->input, &remainder, test->base);
		err = get_errno();
		assert_d_eq(err, test->expected_errno,
		    "Expected errno %s for \"%s\", base %d",
		    test->expected_errno_name, test->input, test->base);
		assert_str_eq(remainder, test->expected_remainder,
		    "Unexpected remainder for \"%s\", base %d",
		    test->input, test->base);
		if (err == 0) {
			assert_ju_eq(result, test->expected_x,
			    "Unexpected result for \"%s\", base %d",
			    test->input, test->base);
		}
	}
}
TEST_END

TEST_BEGIN(test_malloc_snprintf_truncated)
{
#define	BUFLEN	15
	char buf[BUFLEN];
	int result;
	size_t len;
#define TEST(expected_str_untruncated, fmt...) do {			\
	result = malloc_snprintf(buf, len, fmt);			\
	assert_d_eq(strncmp(buf, expected_str_untruncated, len-1), 0,	\
	    "Unexpected string inequality (\"%s\" vs \"%s\")",		\
	    buf, expected_str_untruncated);		\
	assert_d_eq(result, strlen(expected_str_untruncated),		\
	    "Unexpected result");					\
} while (0)

	for (len = 1; len < BUFLEN; len++) {
		TEST("012346789",	"012346789");
		TEST("a0123b",		"a%sb", "0123");
		TEST("a01234567",	"a%s%s", "0123", "4567");
		TEST("a0123  ",		"a%-6s", "0123");
		TEST("a  0123",		"a%6s", "0123");
		TEST("a   012",		"a%6.3s", "0123");
		TEST("a   012",		"a%*.*s", 6, 3, "0123");
		TEST("a 123b",		"a% db", 123);
		TEST("a123b",		"a%-db", 123);
		TEST("a-123b",		"a%-db", -123);
		TEST("a+123b",		"a%+db", 123);
	}
#undef BUFLEN
#undef TEST
}
TEST_END

TEST_BEGIN(test_malloc_snprintf)
{
#define	BUFLEN	128
	char buf[BUFLEN];
	int result;
#define	TEST(expected_str, fmt...) do {					\
	result = malloc_snprintf(buf, sizeof(buf), fmt);		\
	assert_str_eq(buf, expected_str, "Unexpected output");		\
	assert_d_eq(result, strlen(expected_str), "Unexpected result");	\
} while (0)

	TEST("hello", "hello");

	TEST("50%, 100%", "50%%, %d%%", 100);

	TEST("a0123b", "a%sb", "0123");

	TEST("a 0123b", "a%5sb", "0123");
	TEST("a 0123b", "a%*sb", 5, "0123");

	TEST("a0123 b", "a%-5sb", "0123");
	TEST("a0123b", "a%*sb", -1, "0123");
	TEST("a0123 b", "a%*sb", -5, "0123");
	TEST("a0123 b", "a%-*sb", -5, "0123");

	TEST("a012b", "a%.3sb", "0123");
	TEST("a012b", "a%.*sb", 3, "0123");
	TEST("a0123b", "a%.*sb", -3, "0123");

	TEST("a  012b", "a%5.3sb", "0123");
	TEST("a  012b", "a%5.*sb", 3, "0123");
	TEST("a  012b", "a%*.3sb", 5, "0123");
	TEST("a  012b", "a%*.*sb", 5, 3, "0123");
	TEST("a 0123b", "a%*.*sb", 5, -3, "0123");

	TEST("_abcd_", "_%x_", 0xabcd);
	TEST("_0xabcd_", "_%#x_", 0xabcd);
	TEST("_1234_", "_%o_", 01234);
	TEST("_01234_", "_%#o_", 01234);
	TEST("_1234_", "_%u_", 1234);

	TEST("_1234_", "_%d_", 1234);
	TEST("_ 1234_", "_% d_", 1234);
	TEST("_+1234_", "_%+d_", 1234);
	TEST("_-1234_", "_%d_", -1234);
	TEST("_-1234_", "_% d_", -1234);
	TEST("_-1234_", "_%+d_", -1234);

	TEST("_-1234_", "_%d_", -1234);
	TEST("_1234_", "_%d_", 1234);
	TEST("_-1234_", "_%i_", -1234);
	TEST("_1234_", "_%i_", 1234);
	TEST("_01234_", "_%#o_", 01234);
	TEST("_1234_", "_%u_", 1234);
	TEST("_0x1234abc_", "_%#x_", 0x1234abc);
	TEST("_0X1234ABC_", "_%#X_", 0x1234abc);
	TEST("_c_", "_%c_", 'c');
	TEST("_string_", "_%s_", "string");
	TEST("_0x42_", "_%p_", ((void *)0x42));

	TEST("_-1234_", "_%ld_", ((long)-1234));
	TEST("_1234_", "_%ld_", ((long)1234));
	TEST("_-1234_", "_%li_", ((long)-1234));
	TEST("_1234_", "_%li_", ((long)1234));
	TEST("_01234_", "_%#lo_", ((long)01234));
	TEST("_1234_", "_%lu_", ((long)1234));
	TEST("_0x1234abc_", "_%#lx_", ((long)0x1234abc));
	TEST("_0X1234ABC_", "_%#lX_", ((long)0x1234ABC));

	TEST("_-1234_", "_%lld_", ((long long)-1234));
	TEST("_1234_", "_%lld_", ((long long)1234));
	TEST("_-1234_", "_%lli_", ((long long)-1234));
	TEST("_1234_", "_%lli_", ((long long)1234));
	TEST("_01234_", "_%#llo_", ((long long)01234));
	TEST("_1234_", "_%llu_", ((long long)1234));
	TEST("_0x1234abc_", "_%#llx_", ((long long)0x1234abc));
	TEST("_0X1234ABC_", "_%#llX_", ((long long)0x1234ABC));

	TEST("_-1234_", "_%qd_", ((long long)-1234));
	TEST("_1234_", "_%qd_", ((long long)1234));
	TEST("_-1234_", "_%qi_", ((long long)-1234));
	TEST("_1234_", "_%qi_", ((long long)1234));
	TEST("_01234_", "_%#qo_", ((long long)01234));
	TEST("_1234_", "_%qu_", ((long long)1234));
	TEST("_0x1234abc_", "_%#qx_", ((long long)0x1234abc));
	TEST("_0X1234ABC_", "_%#qX_", ((long long)0x1234ABC));

	TEST("_-1234_", "_%jd_", ((intmax_t)-1234));
	TEST("_1234_", "_%jd_", ((intmax_t)1234));
	TEST("_-1234_", "_%ji_", ((intmax_t)-1234));
	TEST("_1234_", "_%ji_", ((intmax_t)1234));
	TEST("_01234_", "_%#jo_", ((intmax_t)01234));
	TEST("_1234_", "_%ju_", ((intmax_t)1234));
	TEST("_0x1234abc_", "_%#jx_", ((intmax_t)0x1234abc));
	TEST("_0X1234ABC_", "_%#jX_", ((intmax_t)0x1234ABC));

	TEST("_1234_", "_%td_", ((ptrdiff_t)1234));
	TEST("_-1234_", "_%td_", ((ptrdiff_t)-1234));
	TEST("_1234_", "_%ti_", ((ptrdiff_t)1234));
	TEST("_-1234_", "_%ti_", ((ptrdiff_t)-1234));

	TEST("_-1234_", "_%zd_", ((ssize_t)-1234));
	TEST("_1234_", "_%zd_", ((ssize_t)1234));
	TEST("_-1234_", "_%zi_", ((ssize_t)-1234));
	TEST("_1234_", "_%zi_", ((ssize_t)1234));
	TEST("_01234_", "_%#zo_", ((ssize_t)01234));
	TEST("_1234_", "_%zu_", ((ssize_t)1234));
	TEST("_0x1234abc_", "_%#zx_", ((ssize_t)0x1234abc));
	TEST("_0X1234ABC_", "_%#zX_", ((ssize_t)0x1234ABC));
#undef BUFLEN
}
TEST_END

int
main(void)
{

	return (test(
	    test_pow2_ceil,
	    test_malloc_strtoumax_no_endptr,
	    test_malloc_strtoumax,
	    test_malloc_snprintf_truncated,
	    test_malloc_snprintf));
}
