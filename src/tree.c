#include "tree.h"
#include <stdio.h>
#include <stdlib.h>



Tree constructor(char **grille, Tree a1, Tree a2){
    Tree a = malloc(sizeof(Tree));
    a->c = grille;
    a->g = a1;
    a->d = a2;
    return a;
}
