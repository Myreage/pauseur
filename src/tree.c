#include "tree.h"
#include <stdio.h>
#include <stdlib.h>



NTree newTree(char** g){
    int i;
    NTree tree = malloc(sizeof(NNode));
    tree->c = g;
    for(i=0;i<MAXCHILDREN;i++){
        tree->tabChildren[i] = NULL;
    }
    tree->nbChildren = 0;

    return tree;
}


NTree addChild(NTree a, NTree child){
    if(a->nbChildren == MAXCHILDREN){
        printf("Too much children !\n");
        return a;
    }
    else{
        a->tabChildren[a->nbChildren] = child;
        a->nbChildren += 1;
    }
    return a;
}
