#include <stdlib.h>
#include <stdio.h>
#include "datastruct.h"
#include "colors.h"
/**
 *
 * @param Matrice de connexité.
 * @param n taille du tableau.
 * @return Test de la condition de victoire : si un élèment de la matrice de connexité est nul, renvoie 0, sinon, renvoie 1.
 */
int wintest(int **connexetab, int n){
    /**

     */
    int i,j;
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            if (connexetab[i][j] != 1) return 0;
        }
    }
    return 1;

}
/**
 *
 * @param connexetab
 * @param x coordonnée du point
 * @param y coordonnée du point
 * @param n taille du tableau
 * @return renvoie 1 si la case selectionée en (x,y) fait parti de la composante connexe.
 */
int isconnexe(int **connexetab, int x, int y, int n){
    int res;
    if (connexetab[x][y]) res=1;
    else if (x+1<n && connexetab[x+1][y]==1) res=1;
    else if (x-1>=0 && connexetab[x-1][y]==1) res=1;
    else if (y+1<n && connexetab[x][y+1]==1) res=1;
    else if (y-1>=0 && connexetab[x][y-1]==1) res=1;
    else res=0;
    return res;
}
/**
 *
 * @param colortable Tableau de couleur
 * @param connexetab Matrice de connexité
 * @param color Couleur séléctionnée
 * @param n taille du tableau
 * Met à jour la matrice de connexité en fonction de la couleur entrée en paramètre.
 */
void updateconnexetab(char **colortable, int **connexetab, char color, int n){
    int i,j;
    int modif=1;
    while (modif) {
        /**
         * Un seul parcourt ne suffit pas tout le temps à remplir correctement la matrice de connexité,
         * à cause de certaines tâches possibles.
         * On modifie donc la matrice jusqu'à ce qu'aucun changement ne soit plus effectué.
         */
        modif = 0;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (isconnexe(connexetab, i, j, n) && colortable[i][j] == color && connexetab[i][j]==0){
                    connexetab[i][j] = 1;
                    modif+=1;
                }
            }
        }
    }

}
/**
 *
 * @param colortable Tableau de couleur
 * @param connexetab Matrice de connexité
 * @param color Couleur séléctionnée
 * @param n taille du tableau
 *
 * Change la couleurs de toutes les cases de la composante connexe par la couleur souhaitée.
 *
 */
void switchconnexecolors(char **colortable, int **connexetab, char color, int n){
    updateconnexetab(colortable, connexetab, color, n);
    int i,j;
    for (i=0; i<n;i++){
        for (j=0; j<n; j++){
            if (connexetab[i][j]==1) switchcolor(colortable, color, i, j);
        }
    }
}
