#include <stdio.h>
#include <stdlib.h>

#ifndef PAUSEUR_TREE_H
#define PAUSEUR_TREE_H

#define MAXCHILDREN 10

typedef struct t_ntree {
    char** c;
    struct t_narbre *tabChildren[MAXCHILDREN];
    int nbChildren;

} NNode, *NTree;


NTree constructor(char **grille, NTree a1, NTree a2);

#endif //PAUSEUR_TREE_H
