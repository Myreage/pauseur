#include <stdlib.h>
#include <stdio.h>

#include "solver.h"
#include "pile.h"

#include "datastruct.h"
#include "colors.h"

int main(){
  int n=5;
  pile *p = initpile();
  int kmax = 1000000;
  int nbiterate=0;



  char **col = createcolortable(n);
  int **con = createconnexetab(n);



  fillcolortablerand(col,n);
  displaycolortable(col,n);

  char **colortemp=copycolortable(col, n);
  int **connextemp=copyconnexetab(con, n);

  printf("===> Recherche de toutes les solutions :\n");

  solver(colortemp,connextemp,p,n,&kmax,&nbiterate);


  displayconnexetab(con, n);
  displaycolortable(col, n);




  return 0;
}
