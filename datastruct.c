#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "datastruct.h"

char **createcolortable(int n){
    /**
     * Créer une matrice de taille n*n de char.
     */
    int i;
    char **colortable=NULL;
    colortable=malloc(n*sizeof(char *));
    for (i=0;i<n;i++) colortable[i]=malloc(n*sizeof(char));
    return colortable;
}

int **createconnexetab(int n){
    /**
     * Créer une matrice de connexité : Elle a pour but de marquer les cases qui appartiennent à la composante connexe.
     * Contient un 1 si la cases est dans la composante connexe, 0 sinon.
     */
    int i;
    int **tab=NULL;
    tab=malloc(n*sizeof(int *));
    for (i=0;i<n;i++) tab[i]=malloc(n*sizeof(int));
    return tab;
}

void freecolortable(char **colortable, int n){
    /**
     * Libère l'espace mémoire attribué à la matrice de couleur
     */
    int i;
    for (i=0;i<n;i++){
        free(colortable[i]);
    }
    free(colortable);
}

void freeconnextab(int **connextab, int n){
    /**
     * Libère l'espace mémoire attribu à la matrice de connexité.
     */
    int i;
    for (i=0;i<n;i++){
        free(connextab[i]);
    }
    free(connextab);
}

void fillcolortablerand(char **colortable, int n){
    /**
     * Rempli une matrice de couleur de valeures aléatoires.
     */
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
     * Rempli une matrice de couleur à partir d'un fichier.
     * L'entrée attendu est un fichier conforme aux règles du jeux, c'est à dire ne contenant que les couleures autorisées,
     * n lignes et n colonnes, sans espaces.
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
    /**
     * Génère un fichier de couleur aléatoire, conforme aux conditions d'entrée de la fonction de remplissage
     * de la table de couleur à partir d'un fichier.
     */
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
    /**
     * Change la couleur de la case (x,y) par la couleur entrée en paramètre.
     */
    if (colortable[x][y] == ' ') printf("Error switch color\n");
    else colortable[x][y] = color;
}

void displaycolortable(char **colortable, int n){
    /**
     * Affiche la matrice de couleur entrée en paramètre.
     */
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
    /**
     * Affiche la matrice de connexité entrée en paramètres.
     */
    int i,j;
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            printf("%d",tab[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}