#include "executor/executor.h"
#include <stdio.h>

int main() {
    printf("executor id is %d\n", executor_get_id());
    return 0;
}