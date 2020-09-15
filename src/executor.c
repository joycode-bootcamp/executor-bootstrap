#include "executor/executor.h"
#include "executor_id.h"
#include <string.h>

typedef enum BOOL{
    TRUE, FALSE,
}BOOL;

BOOL all_ids[MAX_ID_NUM];

int executor_id_generate(ALLOC_TYPE type) {
    u_int16_t allocId = 0;
    switch (type) {
        case INCREASE: {
            for (u_int16_t i = 0; i < MAX_ID_NUM; i++) {
                if (all_ids[i] == FALSE) {
                    all_ids[i] = TRUE;
                    allocId = i;
                    break;
                }
            }
            break;
        }
        case DECREASE: {
            for (u_int16_t i = MAX_ID_NUM - 1; i >= 0; i--) {
                if (all_ids[i] == FALSE) {
                    all_ids[i] = TRUE;
                    allocId = i;
                    break;
                }
            }
            break;
        }
        default:
            break;
    }
    return allocId;
}

void reset() {
    for (u_int16_t i = 0; i < MAX_ID_NUM; i++) {
        all_ids[i] = FALSE;
    }
}

int executor_get_id() {
	return executor_id_generate(NOT_SET);
}