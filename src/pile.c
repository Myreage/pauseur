#include <stdlib.h>
#include <stdio.h>
#include "pile.h"


pile *initpile(){
    pile *res=malloc(sizeof(*res));
    res->length=0;
    res->first=NULL;
    return res;
}
void stack(pile *pile, char value){

    if(pile != NULL ){

      f_Element *newelt=malloc(sizeof(*newelt));
      newelt->value=value;
      newelt->next=pile->first;

      pile->first=newelt;
      pile->length++;



    }

    else exit(1);




}

char pop(pile *pile){
    if (pile==NULL){
        perror("pop");
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

void freepile(pile *pile){
    while(pile->first !=NULL){
        pop(pile);
    }
    free(pile);
}
void displaypile(pile * pile){
    f_Element* aux = pile->first;
    printf("[  ");
    while(aux != NULL){
        printf("%c  ", aux->value);
        aux = aux->next;
    }
    printf("]\n");
}

void displayreversepile(pile * pile){

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
