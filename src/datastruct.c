#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "datastruct.h"

/**
 * @param n taille du tableau.
 * @return renvoie une Matrice de couleur initialisée de taille n.
 */
char **createcolortable(int n){
    int i;
    char **colortable=NULL;
    colortable=malloc(n*sizeof(char *));
    for (i=0;i<n;i++) colortable[i]=malloc(n*sizeof(char));
    return colortable;
}
/**
 * @param n taille du tableau.
 * @return renvoie une Matrice de connexité initialisée de taille n : : Elle a pour but de marquer les cases qui appartiennent à la composante connexe.
 * Contient un 1 si la cases est dans la composante connexe, 0 sinon.
 */
int **createconnexetab(int n){
    int i;
    int **tab=NULL;
    tab=malloc(n*sizeof(int *));
    for (i=0;i<n;i++) tab[i]=calloc(n,sizeof(int));
    tab[0][0]=1;
    return tab;
}
/**
 * @param colortable Matrice de couleur
 * @param n taille de la matrice de couleur.
 * Libère l'espace mémoire attribué à la matrice de couleur
 */
void freecolortable(char **colortable, int n){
    int i;
    for (i=0;i<n;i++){
        free(colortable[i]);
    }
    free(colortable);
}
/**
 *
 * @param connextab Matrice de connexité
 * @param n taille de la matrice de connexité
 * Libère l'espace mémoire attribu à la matrice de connexité.
 */
void freeconnextab(int **connextab, int n){
    int i;
    for (i=0;i<n;i++){
        free(connextab[i]);
    }
    free(connextab);
}
/**
 *
 * @param colortable Matrice de couleur
 * @param n taille de la matrice de couleur
 * Rempli une matrice de couleur aléatoirement a partir des valeures autorisées.
 */
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

/**
 *
 * @param colortable matrice de couleur
 * @param n taille de la matrice de couleur
 * @param filename nom du fichier
 * Rempli une matrice de couleur à partir d'un fichier.
 * L'entrée attendu est un fichier conforme aux règles du jeux, c'est à dire ne contenant que les couleures autorisées, n lignes et n colonnes, sans espaces.
 */
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
/**
 *
 * @param filename nom du fichier à créer.
 * @param n taille de la matrice crée dans le fichier.
 * Génère un fichier de couleur aléatoire, conforme aux conditions d'entrée de la fonction de remplissage
 * de la table de couleur à partir d'un fichier.
 */
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
/**
 *
 * @param colortable matrice de couleur
 * @param color nouvelle couleur de la case
 * @param x coordonnée du point
 * @param y coordonnée du point
 *
 * Change la couleur de la case (x,y) par la couleur entrée en paramètre.
 */

void switchcolor(char **colortable, char color, int x, int y) {
    if (colortable[x][y] == ' ') printf("Error switch color\n");
    else colortable[x][y] = color;
}
/**
 *
 * @param colortable matrice de couleur
 * @param n Taille de la matrice de couleur
 * Affiche la matrice de couleur entrée en paramètre.
 */
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

/**
 *
 * @param tab matrice de connexité
 * @param n taille de la matrice de conexité
 * Affiche la matrice de connexité.
 */
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