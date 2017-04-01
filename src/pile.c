#include <stdlib.h>
#include <stdio.h>
#include "pile.h"


fifo *initpile(){
    fifo *res=malloc(sizeof(fifo *));
    res->length=0;
    res->first=NULL;
    return res;
}
void thread(fifo *file, char value){
    f_Element *newelt=malloc(sizeof(f_Element *));

    if (newelt==NULL){
        perror("thread");
        exit(EXIT_FAILURE);
    }


    newelt->value=value;
    if(file != NULL ) newelt->next=file->first;
    else newelt->next = NULL;


    file->length++;
    file->first=newelt;

}

char popfirst(fifo *pile){
    if (pile==NULL){
        perror("popfirst");
        exit(EXIT_FAILURE);
    }
    int res;

    if(pile->first!=NULL){
        f_Element *temp=pile->first;

        res=temp->value;
        pile->first=temp->next;
        free(temp);
    }

    pile->length--;
    return res;
}

void freefifo(fifo *pile){
    while(pile!=NULL){
        popfirst(pile);
    }
    free(pile);
}
void displayfifo(fifo * pile){
    f_Element* aux = pile->first;
    printf("[  ");
    while(aux != NULL){
        printf("%c  ", aux->value);
        aux = aux->next;
    }
    printf("]\n");
}

void displayreversefifo(fifo * pile){

  char auxtab[pile->length];

  int i=0;

  f_Element* aux = pile->first;


  while(aux != NULL){
      auxtab[i] = aux->value;
      aux = aux->next;
      i++;
  }


  printf("[ ");
  for(i=i-1;i>=0;i--){

    printf("%c", auxtab[i]);
  }
  printf(" ]");



}

fifo *copyfifo(fifo *pile, int maxlenght){
    fifo *res=initpile();
    int k=0;
    f_Element *temp=pile->first;
    while(temp!=NULL || k<maxlenght){
        thread(res, temp->value);
        k++;
    }
    return res;
}

char *getElement(fifo *pile, int k){
    f_Element *temp=pile->first;
    int p=0;
    while(temp!=NULL || p!=k){
        temp=temp->next;
        p++;
    }
    return temp;
}
