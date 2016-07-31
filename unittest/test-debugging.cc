#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <functional>

#include "gtest/gtest.h"
#include "common/plateform.h"
#include "common/ultils/ultils.h"
#include "common/debugging/debug.h"

using namespace geco::debugging;
using namespace geco::ultils;
using namespace geco::ds;

DECLARE_DEBUG_COMPONENT2("UNIT-TEST", 0);

TEST(GECO_DEBUGGING_MSGLOG, test_msg_macros)
{
	Leave("test_msg_macros", "test_msg_macros");
	Enter("test_msg_macros", "test_msg_macros");
	TRACE_MSG("TRACE_MSG\n");
	DEBUG_MSG("DEBUG_MSG %d\n", 12);
	INFO_MSG("INFO_MSG %s\n", "hello world");
	NOTICE_MSG("NOTICE_MSG %s\n", "hello world");
	ERROR_MSG("ERROR_MSG %s\n", "hello world");
}
TEST(GECO_DEBUGGING_MSGLOG, geco_asset_dev_cause_real_assertion_when_has_dev_assert_is_false)
{
	// Runtime disable fatal assertions
	geco::debugging::log_msg_filter_t::get_instance().has_dev_assert_ = false;
	// when has_dev_assert_ = false, GECO_ASSERT will not cause a REAL assert
	GECO_ASSERT_DEV(false);
}
TEST(GECO_DEBUGGING_MSGLOG, geco_asset_dev_cause_real_assertion_when_has_dev_assert_is_true)
{
	// Runtime enable dev fatal assertions
	geco::debugging::log_msg_filter_t::get_instance().has_dev_assert_ = true;
	// when has_dev_assert_ = true (default), GECO_ASSERT will cause a REAL assert like GECO_ASSERT_DEV
	GECO_ASSERT_DEV(false);
}

TEST(GECO_DEBUGGING_MSGLOG, geco_asset_dev_if_not_does_block_codes_will_not_run_when_has_dev_assert_is_true_and_assert_value_false)
{
	// when has_dev_assert_ = true (default), GECO_ASSERT_DEV_IFNOT will cause a REAL assert like GECO_ASSERT_DEV
	bool runblockcodes = false;
	log_msg_filter_t::get_instance().has_dev_assert_ = true;
	GECO_ASSERT_DEV_IFNOT(false)
	{
		runblockcodes = true;
		INFO_MSG("you should not see me as has_dev_assert_ == true.\n\n");
	}
	EXPECT_FALSE(runblockcodes);
}
TEST(GECO_DEBUGGING_MSGLOG, geco_asset_dev_if_not_does_block_codes_will_not_run_when_has_dev_assert_is_true_and_assert_value_true)
{
	// when has_dev_assert_ = true (default), GECO_ASSERT_DEV_IFNOT will cause a REAL assert like GECO_ASSERT_DEV
	bool runblockcodes = false;
	log_msg_filter_t::get_instance().has_dev_assert_ = true;
	GECO_ASSERT_DEV_IFNOT(true)
	{
		runblockcodes = true;
		INFO_MSG("you should not see me as it is true.\n");
	}
	EXPECT_FALSE(runblockcodes);
}
TEST(GECO_DEBUGGING_MSGLOG, geco_asset_dev_if_not_does_block_codes_will_run_when_has_dev_assert_is_false_and_assert_value_false)
{
	// when has_dev_assert_ = true (default), GECO_ASSERT_DEV_IFNOT will cause a REAL assert like GECO_ASSERT_DEV
	bool runblockcodes = false;
	log_msg_filter_t::get_instance().has_dev_assert_ = false;
	GECO_ASSERT_DEV_IFNOT(false)
	{
		runblockcodes = true;
		INFO_MSG("you should see me as has_dev_assert_ == false and asserts false.\n\n");
	}
	EXPECT_TRUE(runblockcodes);
}
TEST(GECO_DEBUGGING_MSGLOG, geco_asset_dev_if_not_does_block_codes_will_not_run_when_has_dev_assert_is_false_and_assert_value_true)
{
	// when has_dev_assert_ = true (default), GECO_ASSERT_DEV_IFNOT will cause a REAL assert like GECO_ASSERT_DEV
	bool runblockcodes = false;
	log_msg_filter_t::get_instance().has_dev_assert_ = false;
	GECO_ASSERT_DEV_IFNOT(true)
	{
		runblockcodes = true;
		INFO_MSG("you should not see me as it is true.\n");
	}
	EXPECT_FALSE(runblockcodes);
}

