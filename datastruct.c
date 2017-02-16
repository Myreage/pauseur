#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "datastruct.h"

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

int testfile (char *filename, int n){
    FILE *file=fopen(filename, "r");
    int res=1;
    int i,j;
    char temp;
    if (file==NULL) res=0;
    for (i=0; i<n; i++){
        for (j=0; j<n; j++){
            temp=fgetc(file);
            if (temp!='B' && temp!='V' && temp!='R' && temp!='J' && temp!='M' && temp!='G') res=0;
        }
        fseek(file,1,SEEK_CUR);
    }
    return res;

}

void fillcolortablefile(char **colortable, int n, char *filename){
    FILE *file=fopen(filename, "r");
    int i,j;
    if (testfile(filename, n)) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                colortable[i][j] = fgetc(file);
            }
            fseek(file, 1, SEEK_CUR);
        }
    }
    else {
        printf("Invalid File\n");
        exit(0);
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


