#include <stdlib.h>
#include <stdio.h>

#include "solver.h"
#include "pile.h"

#include "datastruct.h"
#include "colors.h"

int main(int argc, char *argv[]){
  if (argc!=2){
      printf("Executer sous forme ./slvColorflood <tailleMat>\n");
      exit(0);
  }

  int n=atoi(argv[1]);



  pile *p = initpile();
  int kmax = 1000000;
  int nbiterate=0;



  char **col = createcolortable(n);
  int **con = createconnexetab(n);



  fillcolortablerand(col,n);
  displaycolortable(col,n);

  updateconnexetab(col, con, col[0][0], n);
  switchconnexecolors(col, con, col[0][0], n);

  char **colortemp=copycolortable(col, n);
  int **connextemp=copyconnexetab(con, n);

  printf("===> Recherche de toutes les solutions :\n");

  solver(colortemp,connextemp,p,n,&kmax,&nbiterate);


  displayconnexetab(con, n);
  displaycolortable(col, n);

  freecolortable(col,n);
  freecolortable(colortemp,n);
  freeconnextab(connextemp,n);
  freeconnextab(con,n);
  freepile(p);




  return 0;
}
