#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "datastruct.h"


char **createcolortable(int n){
    int i;
    char **colortable=NULL;
    colortable=malloc(n*sizeof(char *));
    for (i=0;i<n;i++) colortable[i]=malloc(n*sizeof(char));
    return colortable;
}

int **createconnexetab(int n){
    int i;
    int **tab=NULL;
    tab=malloc(n*sizeof(int *));
    for (i=0;i<n;i++) tab[i]=calloc(n,sizeof(int));
    tab[0][0]=1;
    return tab;
}

void freecolortable(char **colortable, int n){
    int i;
    for (i=0;i<n;i++){
        free(colortable[i]);
    }
    free(colortable);
}


void freeconnextab(int **connextab, int n){
    int i;
    for (i=0;i<n;i++){
        free(connextab[i]);
    }
    free(connextab);
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
    /**

     */
    FILE *file=fopen(filename, "r");
    int i,j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            colortable[i][j] = fgetc(file);
        }
        fseek(file, 1, SEEK_CUR);
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

    fclose(file);
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


void displayconnexetab(int **tab, int n){
    int i,j;
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            printf("%d",tab[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}