#include <stdlib.h>
#include <stdio.h>

#include "solver.h"
#include "pile.h"
#include "tree.h"

#include "datastruct.h"
#include "colors.h"
#include <time.h>

int main(int argc, char *argv[]){
  if (argc!=2){
      printf("Executer sous forme ./slvColorflood <tailleMat>\n");
      exit(0);
  }
  float time;
  clock_t t1, t2;


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

  NTree tree = newTree(col,con,0,0);


  printf("===> Recherche de toutes les solutions avec le solver simple :\n");

  t1=clock();

  solver(colortemp,connextemp,p,n,&kmax,&nbiterate);

  t2=clock();

  time=(float)(t2-t1)/CLOCKS_PER_SEC;
  printf("Temps d'execution : %f secondes\n", time);

  printf("===> Génération de l'arbre des solutions :\n");

  t1=clock();



  solverTree(tree,col,con,n,7);


  t2=clock();






  time=(float)(t2-t1)/CLOCKS_PER_SEC;
  printf("Temps d'execution : %f secondes\n", time);



  freecolortable(col,n);
  freecolortable(colortemp,n);
  freeconnextab(connextemp,n);
  freeconnextab(con,n);
  freepile(p);


  return 0;
}
