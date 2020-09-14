#include <cctest/cctest.h>
#include <mockcpp/mockcpp.hpp>
#include "executor/executor.h"
#include "executor_id.h"
#include "mcl/log.h"

FIXTURE(ExecutorTest) {
	BEFORE {
		MCL_INFO("TEST SETUP");
	}

	AFTER{
		MCL_INFO("TEST TEARDOWN");
	}

	TEST("should get executor name") {
		MCL_DBG("TEST RUNING...");
		ASSERT_EQ(0, executor_get_id());
		MCL_SUCC("TEST SUCCESS!");
	}

    TEST("should get exeuctor name by mock id") {
	    MOCKER(executor_id_generate).expects(once()).will(returnValue(1));
        ASSERT_EQ(1, executor_get_id());
        GlobalMockObject::verify();
    }
};
