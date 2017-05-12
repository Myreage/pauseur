#include "tree.h"
#include <stdio.h>
#include <stdlib.h>



NTree newTree(char** g, int** con, int win, char col){
    int i;
    NTree tree = malloc(sizeof(NNode));
    tree->c = g;
    tree->con = con;
    tree->win = win;
    tree->col = col;
    for(i=0;i<MAXCHILDREN;i++){
        tree->tabChildren[i] = NULL;
    }
    tree->nbChildren = 0;

    return tree;
}



NTree addChild(NTree a, NTree child){
    if(a->nbChildren == MAXCHILDREN){
        printf("Too many children !\n");
        return a;
    }
    else{
        a->tabChildren[a->nbChildren] = child;
        a->nbChildren += 1;
    }
    return a;
}

void printTree(NTree a, int p){
    int i;
    if(a != NULL){

        printf("n%d ", p);
        printf("[label=%c];\n", a->col);
        if(p != 0){
            printf("n%d -> n%d;\n", (p-1)/MAXCHILDREN, p);
        }
        for(i=0; i<a->nbChildren;i++){
            printTree(a->tabChildren[i], MAXCHILDREN*p+i+1);
        }
    }
}

