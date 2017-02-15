#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include <CUnit/Basic.h>


char **createcolortable(int n){
    int i;
    char **colortable=NULL;
    colortable=malloc(n*n*sizeof(char));
    for (i=0;i<n;i++) colortable[i]=malloc(n*sizeof(char));
    return colortable;
}

void freecolortable(char **colortable, int n){
    int i;
    for (i=0;i<n;i++){
        free(colortable[i]);
    }
    free(colortable);
}

void fillcolortablerand(char **colortable, int n){
    int i,j;
    srand(time(NULL));
    char colors[6]={'B','V','R','J','M','G'};
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            colortable[i][j]=colors[rand()%6];
        }
    }
}

void fillcolortablefile(char **colortable, int n, char *filename){
    FILE *file=fopen(filename, "r");
    int i,j;
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            colortable[i][j]=fgetc(file);
        }
        fseek(file,1,SEEK_CUR);
    }
    fclose(file);
}

void createnewcolorfile(char *filename, int n){
    int i,j;
    srand(time(NULL));
    char colors[6]={'B','V','R','J','M','G'};
    FILE *file=fopen(filename, "w");
    for (i=0; i<n; i++){
        for (j=0; j<n; j++){
            fputc( colors[rand()%6], file);
        }
        fprintf(file, "\n");
    }
}
void switchcolor(char **colortable, char color, int x, int y) {
    if (colortable[x][y] == ' ') printf("Error switch color\n");
    else colortable[x][y] = color;
}

void displaycolortable(char **colortable, int n){
    int i,j;
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            printf("%c",colortable[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

/**************** TESTS ***********************/


/* lancer les tests : CU_automated_run_tests(void) */

/*SAMPLE*/

/* Test Suite setup and cleanup functions: */

int init_suite(void) { return 0; }
int clean_suite(void) { return 0; }

/************* Test case functions ****************/


void test_createcolortable(void) {
    CU_ASSERT(sizeof(createcolortable(5)) == sizeof(char**));
}

void test_freecolortable(void) {
    CU_ASSERT(1 == 1);
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
    //CU_automated_run_tests();
    //printf("\n");
    //CU_basic_show_failures(CU_get_failure_list());
    //printf("\n\n");

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();

}
