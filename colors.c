#include <stdlib.h>
#include <stdio.h>
#include "datastruct.h"
#include "colors.h"

int wintest(int **connexetab, int n){
    /**
     * Test de la condition de victoire : si un élèment de la matrice de connexité est nul, renvoie 0,
     * sinon, renvoie 1.
     */
    int i,j;
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            if (connexetab[i][j] != 1) return 0;
        }
    }
    return 1;

}

int isconnexe(int **connexetab, int x, int y, int n){
    /**
     * Determine si la case séléctionée aux coordonnées (x,y) fait parti de la composante connexe.
     */
    int res;
    if (connexetab[x][y]) res=1;
    else if (x+1<n && connexetab[x+1][y]==1) res=1;
    else if (x-1>=0 && connexetab[x-1][y]==1) res=1;
    else if (y+1<n && connexetab[x][y+1]==1) res=1;
    else if (y-1>=0 && connexetab[x][y-1]==1) res=1;
    else res=0;
    return res;
}

void updateconnexetab(char **colortable, int **connexetab, char color, int n){
    /**
     * Met à jour la matrice de connexité.
     */
    int i,j;
    char **temp=createcolortable(n);
    while (colortable!=temp) {
        /**
         * Un seul parcourt ne suffit pas tout le temps à remplir correctement la matrice de connexité,
         * à cause de certaines taches possibles.
         * On modifie donc la matrice jusqu'au moment où aucuns changements n'est detecté.
         */
        temp=colortable;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (isconnexe(connexetab, i, j, n) && colortable[i][j] == color) connexetab[i][j] = 1;
            }
        }
    }
    freecolortable(temp,n);
}

void switchconnexecolors(char **colortable, int **connexetab, char color, int n){
    /**
     * Change la couleurs de toutes les cases de la composante connexe par la couleur souhaitée.
     */
    updateconnexetab(colortable, connexetab, color, n);
    int i,j;
    for (i=0; i<n;i++){
        for (j=0; j<n; j++){
            if (connexetab[i][j]==1) switchcolor(colortable, color, i, j);
        }
    }
}
