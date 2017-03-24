#include <stdlib.h>
#include <stdio.h>
#include "pile.h"


void thread(fifo *file, int value){
    f_Element *newelt=malloc(sizeof(f_Element *));

    if (file==NULL || newelt==NULL){
        perror("thread Error :");
        exit(EXIT_FAILURE);
    }

    newelt->value=value;
    newelt->next=NULL;

    file->length++;
    if (file->first!=NULL){
        f_Element *temp=file->first;
        while (temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newelt;
    }
    else {
        file->first=newelt;
    }
}

char popfirst(fifo *pile){
    if (pile==NULL){
        perror("thread Error :");
        exit(EXIT_FAILURE);
    }
    int res;

    if(pile->first!=NULL){
        f_Element *temp=pile->first;

        res=temp->value;
        pile->first=temp->next;
        free(temp);
    }
    return res;
}

void freefifo(fifo *pile){
    while(pile!=NULL){
        popfirst(pile);
    }
}
void displayfifo(fifo * pile){
    /*Afficher la file*/
}
