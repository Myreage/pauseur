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
  int nbPlays=p->length;
  printf("====     First Solution     ==== \n ");
  displayfifo(p);

  displayconnexetab(con, n);
  displaycolortable(col, n);


  printf("===> Searching for optimised Solution <===\n");








  return 0;
}
