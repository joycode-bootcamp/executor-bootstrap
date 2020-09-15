#include <cctest/cctest.h>
#include "executor/executor.h"
#include "executor_id.h"
#include "mcl/log.h"

FIXTURE(ExecutorTest) {
	BEFORE {
		MCL_INFO("TEST SETUP");
	}

	AFTER{
		MCL_INFO("TEST TEARDOWN");
		reset();
	}

	TEST("should get executor name") {
		MCL_DBG("TEST RUNING...");
		ASSERT_EQ(0, executor_get_id());
		MCL_SUCC("TEST SUCCESS!");
	}

    TEST("should get executor id increase") {
        ASSERT_EQ(0, executor_id_generate(INCREASE));
        ASSERT_EQ(1, executor_id_generate(INCREASE));
    }

    TEST("should get executor id decrease") {
        ASSERT_EQ( MAX_ID_NUM - 1, executor_id_generate(DECREASE));
        ASSERT_EQ(MAX_ID_NUM - 2, executor_id_generate(DECREASE));
    }
};
