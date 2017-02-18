#include <stdlib.h>
#include <stdio.h>
#include "datastruct.h"
#include "colors.h"

int wintest(int **connexetab, int n){
    int i,j;
    int res;
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            if (connexetab[i][j] != 1) return 0;
        }
    }
    return 1;

}

int isconnexe(char **connexetab, int x, int y, int n){
    int res;
    if (connexetab[x][y]) res=1;
    else if (x+1<n && connexetab[x+1][y]==1) res=1;
    else if (x-1>0 && connexetab[x-1][y]==1) res=1;
    else if (y+1<n && connexetab[x][y+1]==1) res=1;
    else if (y-1>0 && connexetab[x][y-1]==1) res=1;
    else res=0;
    return res;
}

void updateconnexetab(char **colortable, char **connexetab, char color, int n){
    /* Je pense que la fonction est à modifier dans le cas ou il y a un groupe de couleurs connexes ou peut être regler le problème
     * avec un while style tant que (connexetable!=updateconnexetab(...)) (En changeant le type de la fonction) */
    int i,j;
    for (i=0; i<n;i++){
        for (j=0; j<n; j++){
            if (isconnexe(connexetab, i, j, n) && colortable[i][j]==color) connexetab[i][j]=1;
        }
    }
}

void switchconnexecolors(char **colortable, char **connexetab, char color, int n){
    updateconnexetab(colortable, connexetab, color, n);
    int i,j;
    for (i=0; i<n;i++){
        for (j=0; j<n; j++){
            if (connexetab[i][j]==1) switchcolor(colortable, color, i, j);
        }
    }
}
