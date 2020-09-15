#ifndef H2EA0FF9D_531D_4CE5_958A_281CEE421A97
#define H2EA0FF9D_531D_4CE5_958A_281CEE421A97

#include "mcl/stdc.h"

MCL_STDC_BEGIN

typedef enum ALLOC_TYPE{
    INCREASE, DECREASE, NOT_SET
}ALLOC_TYPE;

#define MAX_ID_NUM 1000

int executor_id_generate(ALLOC_TYPE type);
void reset();

MCL_STDC_END

#endif
