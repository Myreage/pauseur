#include "datastruct.h"
#include <CUnit/CUnit.h>
#include <CUnit/Automated.h>
#include <stdlib.h>

/* lancer les tests : CU_automated_run_tests(void) */

/*SAMPLE*/

/* Test Suite setup and cleanup functions: */

int init_suite(void) { return 0; }
int clean_suite(void) { return 0; }

/************* Test case functions ****************/


void test_createcolortable(void) {
    CU_ASSERT_PTR_NOT_NULL(createcolortable(5));
}

void test_freecolortable(void) {
    CU_ASSERT_PTR_NULL(freecolortable(createcolortable(5),5));
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
    if ((NULL == CU_add_test(pSuite, "test_createcolortable", test_createcolortable)) ||
        (NULL == CU_add_test(pSuite, "test_freecolortable", test_freecolortable))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Run all tests using the basic interface
    CU_automated_run_tests();
    printf("\n");
    CU_basic_show_failures(CU_get_failure_list());
    printf("\n\n");

    CU_cleanup_registry();
    return CU_get_error();

}
