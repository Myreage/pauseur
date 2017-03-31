#include <stdlib.h>
#include <stdio.h>

#include "solver.h"
#include "pile.h"

#include "datastruct.h"
#include "colors.h"

int main(){
  int n=6;
  fifo *p = initpile();


  char **col = createcolortable(n);
  int **con = createconnexetab(n);



  fillcolortablerand(col,n);
  displaycolortable(col,n);

  char **colortemp=copycolortable(col, n);
  int **connextemp=copyconnexetab(con, n);

  firstsolution(colortemp,connextemp,p,n);
  int kmax=p->length;

  printf("====     Première Solution : %d Coups     ==== \n ", kmax);
  displayfifo(p);

  displayconnexetab(con, n);
  displaycolortable(col, n);


  printf("===> Recherche d'une Solution de moins de %d Coups <===\n", kmax);

  return 0;
}
