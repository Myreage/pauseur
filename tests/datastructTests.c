#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <CUnit/Basic.h>
#include "../datastruct.h"


/**************** TESTS ***********************/


int init_suite(void) { return 0; }
int clean_suite(void) { return 0; }

/************* Test case functions ****************/


void test_createcolortable(void) {
    int n = 5;
    int i;
    CU_ASSERT(sizeof(createcolortable(n)) == sizeof(char**));
    for(i=0;i<n;i++) CU_ASSERT(sizeof(createcolortable(n)[i]) == sizeof(char*));
}

void test_testfillcolortablerand(void){
    char **t = NULL;
    int i,j;
    int n;
    t = createcolortable(n);
    fillcolortablerand(t,n);

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            CU_ASSERT(t[i][j] == 'B' || t[i][j] =='V' || t[i][j] == 'R'
                      || t[i][j] == 'J' || t[i][j] == 'M' || t[i][j] == 'G');
        }
    }

    freecolortable(t,n);

}

void test_createnewcolorfile(void){
    int n = 5;
    int buff;
    int i,j;
    char* filename="test.dat";
    createnewcolorfile(filename,n);
    FILE *file=fopen(filename, "r");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            buff = fgetc(file);
            CU_ASSERT(buff == 'B' || buff =='V' || buff == 'R'
                      || buff == 'J' || buff == 'M' || buff == 'G');
        }
        fseek(file,1,SEEK_CUR);
    }
    fclose(file);
}

void test_fillcolortablefile(void){
    char **t = NULL;
    int n=5;
    char* f = "test.dat";
    t = createcolortable(n);
    createnewcolorfile(f,n);
    fillcolortablefile(t,n,f);

    FILE *file=fopen(f, "r");
    int i,j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            CU_ASSERT(t[i][j] == fgetc(file));
        }
        fseek(file, 1, SEEK_CUR);
    }
    fclose(file);
}

void test_switchcolor(void){
    char **t = NULL;
    int n = 5;
    t = createcolortable(n);
    fillcolortablerand(t,n);
    switchcolor(t,'A',0,0);
    switchcolor(t,'A',n-1,n-1);
    switchcolor(t,'A',n/2,n/2);

    switchcolor(t,'B',0,0); /*coin*/
    CU_ASSERT(t[0][0] == 'B');

    switchcolor(t,'B',n-1,n-1); /*coin*/
    CU_ASSERT(t[n-1][n-1] == 'B');

    switchcolor(t,'B',n/2,n/2); /* dans le tableau */
    CU_ASSERT(t[n/2][n/2] == 'B');

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
