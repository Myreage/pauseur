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
        for(j=0;j<n;j++){
            t[i][j] = 0;
        }
    }

    CU_ASSERT(wintest(t,n) == 0);

    for(i=n/2;i<n;i++){        
        for(j=n/2;j<n;j++){
            t[i][j] = 1;
        }
    }

    CU_ASSERT(wintest(t,n) == 0);

    for(i=0;i<n;i++){
        free(t[i]);
    }
    free(t);

}

void test_isconnexe(void){
    int i,j;
    int n=5;
    int **t = NULL;
    t = malloc(n*sizeof(int*));
    for(i=0;i<n;i++){
        t[i] = malloc(n*sizeof(int));
        for(j=0;j<n;j++){
            if(j>n/2) t[i][j] = 0;
            else t[i][j] = 1;
        }
    }

    CU_ASSERT(isconnexe(t,0,0,n) == 1);
    CU_ASSERT(isconnexe(t,0,n/2,n) == 1);
    CU_ASSERT(isconnexe(t,0,(n/2)+1,n) == 1);
    CU_ASSERT(isconnexe(t,0,(n/2)+2,n) == 0);
    CU_ASSERT(isconnexe(t,n-1,0,n) == 1);

    for(i=0;i<n;i++){
        free(t[i]);
    }
    free(t);

}

void test_updateconnexetab(void){
    int n=3;
    int i,j;
    char **colortab = malloc(n*sizeof(char*));
    int **connexetab = malloc(n*sizeof(int*));
    int **sol = malloc(n*sizeof(int*));

    for(i=0;i<n;i++){
        colortab[i] = malloc(n*sizeof(char));
        connexetab[i] = malloc(n*sizeof(int));
        sol[i] = malloc(n*sizeof(int));
        for(j=0;j<n;j++){
            colortab[i][j] = 'B';
            connexetab[i][j] = 1;
            sol[i][j] = 1;
        }
    }

    colortab[0][1] = 'R';
    colortab[0][2] = 'R';
    colortab[2][2] = 'R';
    colortab[1][2] = 'J';

    connexetab[0][1] = 0;
    connexetab[0][2] = 0;
    connexetab[2][2] = 0;
    connexetab[1][2] = 0;

    sol[1][2] = 0;

    /*colortab ={
            {'B','R','R'},
            {'B','B','J'},
            {'B','B','R'}};



    connexetab = {
            {1,0,0},
            {1,1,0},
            {1,1,0}};

    sol = {
            {1,1,1},
            {1,1,0},
            {1,1,1}};*/

    updateconnexetab(colortab,connexetab,'R',n);

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            CU_ASSERT(sol[i][j] == connexetab[i][j]);
        }

    }

    for(i=0;i<n;i++){
        free(colortab[i]);
        free(connexetab[i]);
        free(sol[i]);
    }
    free(colortab);
    free(connexetab);
    free(sol);
}

void test_switchconnexecolors(void){
    int n=3;
    int i,j;
    char **colortab = malloc(n*sizeof(char*));
    int **connexetab = malloc(n*sizeof(int*));
    char **sol = malloc(n*sizeof(char*));

    for(i=0;i<n;i++){
        colortab[i] = malloc(n*sizeof(char));
        connexetab[i] = malloc(n*sizeof(int));
        sol[i] = malloc(n*sizeof(char));
        for(j=0;j<n;j++){
            colortab[i][j] = 'B';
            connexetab[i][j] = 1;
            sol[i][j] = 'R';
        }
    }

    colortab[0][1] = 'R';
    colortab[0][2] = 'R';
    colortab[2][2] = 'R';
    colortab[1][2] = 'J';

    connexetab[0][1] = 0;
    connexetab[0][2] = 0;
    connexetab[2][2] = 0;
    connexetab[1][2] = 0;

    sol[1][2] = 'J';

    switchconnexecolors(colortab,connexetab,'R',n);

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            CU_ASSERT(sol[i][j] == colortab[i][j]);
        }
        printf("\n");

    }

    for(i=0;i<n;i++){
        free(colortab[i]);
        free(connexetab[i]);
        free(sol[i]);
    }
    free(colortab);
    free(connexetab);
    free(sol);


}



/************* Test Runner Code goes here **************/

int main ( void ) {
    CU_pSuite pSuite = NULL;

    /* initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* add a suite to the registry */
    pSuite = CU_add_suite("colorsTest", init_suite, clean_suite);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }


    /* add the tests to the suite */
    if ((NULL == CU_add_test(pSuite, "test_wintest", test_wintest)) ||
        (NULL == CU_add_test(pSuite, "test_isconnexe", test_isconnexe)) ||
        (NULL == CU_add_test(pSuite, "test_switchconnexecolors", test_switchconnexecolors)) ||
        (NULL == CU_add_test(pSuite, "test_updateconnexetab", test_updateconnexetab))
            ){
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();

}
