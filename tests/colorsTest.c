#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <CUnit/Basic.h>
#include "../colors.h"


/**************** TESTS ***********************/


int init_suite(void) { return 0; }
int clean_suite(void) { return 0; }

/************* Test case functions ****************/

void test_wintest(void){
    int i,j;
    int n=5;
    int **t = NULL;
    t = malloc(n*sizeof(int*));
    for(i=0;i<n;i++){
        t[i] = malloc(n*sizeof(int));
        for(j=0;j<n;j++){
            t[i][j] = 1;
        }
    }

    CU_ASSERT(wintest(t,n) == 1);

    for(i=0;i<n;i++){
        t[i] = malloc(n*sizeof(int));
        for(j=0;j<n;j++){
            t[i][j] = 0;
        }
    }

    CU_ASSERT(wintest(t,n) == 0);

    for(i=n/2;i<n;i++){
        t[i] = malloc(n*sizeof(int));
        for(j=n/2;j<n;j++){
            t[i][j] = 1;
        }
    }

    CU_ASSERT(wintest(t,n) == 0);

}





/************* Test Runner Code goes here **************/

int main ( void ) {
    CU_pSuite pSuite = NULL;

    /* initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* add a suite to the registry */
    pSuite = CU_add_suite("datastrucTests", init_suite, clean_suite);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* add the tests to the suite */
    if ((NULL == CU_add_test(pSuite, "test_wintest", test_wintest))){
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();

}
