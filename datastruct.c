#include <stdlib.h>
#include <stdio.h>
char **createcolortable(int n){
    char **colortable=NULL;
    colortable=malloc(n*n*sizeof(char));

}

void freecolortable(char **colortable, int n){
    int i,j;
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            free(colortable[i][j]);
        }
        free(colortable[i]);
    }
    free(colortable);
}

void fillcolortable(char **colortable, int n){
    int i,j;
    char colors[6]={'B','V','R','J','M','G'};
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            colortable[i][j]=colors[rand()%6];
        }
    }
}

int wintest(char **colortable, int n){
    char color=colortable[0][0];
    int i,j;
    int res;
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            if (colortable[i][j]==color) res++;
        }
    }
    return(res==n*n);

}

/* Rajouter la fonction qui rempli la table a partir d'un fichier*/

void switchcolor(char **colortable, char color, int x, int y) {
    if (colortable[x][y] == NULL) printf("Error switch color\n");
    else colortable[x][y] = color;
}

void updateconnexetab(char **colortable,char **connexetab, int n){ /* Je verrai bien un petit truc recursif */}

void switchconnexecolors(char **colortable, char color, int x, int y){
    int i,j;
    char initcolor=colortable[0][0];
    for (i=0;i<n;i++){
        for (j=0;j<m;j++){
            if ()
        }
    }
}

