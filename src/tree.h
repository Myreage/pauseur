#include <stdio.h>
#include <stdlib.h>

#ifndef PAUSEUR_TREE_H
#define PAUSEUR_TREE_H

typedef struct g_tree {
    char** c;
    struct g_arbre *g, *d;
} Node, *Tree;


Tree constructor(char **grille, Tree a1, Tree a2);

#endif //PAUSEUR_TREE_H
