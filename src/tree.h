#include <stdio.h>
#include <stdlib.h>

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


NTree newTree(char** g, int** con, int win, char col);
NTree addChild(NTree a, NTree child);
void printTree(NTree a, int p);

#endif //PAUSEUR_TREE_H