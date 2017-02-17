#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <CUnit/Basic.h>
#include "../datastruct.h"


/**************** TESTS ***********************/


int init_suite(void) { return 0; }
int clean_suite(void) { return 0; }

/************* Test case functions ****************/





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
    if ((NULL == CU_add_test(pSuite, "test_createcolortable", test_createcolortable)) ||
        (NULL == CU_add_test(pSuite, "test_createnewcolorfile", test_createnewcolorfile)) ||
        (NULL == CU_add_test(pSuite, "test_fillcolortablefile", test_fillcolortablefile)) ||
        (NULL == CU_add_test(pSuite, "test_switchcolor", test_switchcolor)) ||
        (NULL == CU_add_test(pSuite, "test_testfillcolortablerand", test_testfillcolortablerand))){
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();

}
