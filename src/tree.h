#include <stdio.h>
#include <stdlib.h>
#include "datastruct.h"

#ifndef PAUSEUR_TREE_H
#define PAUSEUR_TREE_H

#define MAXCHILDREN 6

typedef struct t_ntree {
    char** c;
    int** con;
    char col;
    int win;
    struct t_ntree *tabChildren[MAXCHILDREN];
    int nbChildren;

} NNode, *NTree;

/**
 * @param g table de couleurs
 * @params con table de connexité
 * @params win situation de victoire (1) ou non (0)
 * @params col couleur jouée pour arriver à cette grille
 * @return arbre initialisé
 */
NTree newTree(char** g, int** con, int win, char col);

/**
 * @param a arbre père
 * @param child arbre fils
 * @return arbre a avec son nouveau fils child
 */
NTree addChild(NTree a, NTree child);

/**
 *
 * @param a arbre à free
 * @param n dimension des tables
 */
void freeTree(NTree a, int n);

/**
 *
 * @param tree arbre à réinitialiser
 * @param g table de couleurs
 * @param con table de connexité
 * @param win victoire(1) ou 0
 * @param col couleur
 * @param n taille des grilles
 */
void initTree(NTree tree, char** g, int** con, int win, char col,int n );

#endif //PAUSEUR_TREE_H
