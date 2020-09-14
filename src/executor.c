#include "executor/executor.h"
#include "executor_id.h"
#include <stdio.h>
#include <string.h>

int executor_id_generate() {
	return 0;
}

int executor_get_id() {
	return executor_id_generate();
}