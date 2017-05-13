#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "solver.h"
#include "pile.h"
#include "tree.h"

#include "datastruct.h"
#include "colors.h"
#include <time.h>

int main(int argc, char *argv[]){
  if (argc!=4){
      printf("Executer sous forme ./slvColorflood [-s;-t;-a] <tailleMat> <depth> \n");
      printf("------------------------------------------------------------------ \n");
      printf("-s : solveur simple bruteforce\n");
      printf("-t : solveur avec arbre/heuristique\n");
      printf("-a : lancer les deux algorithmes\n");
      printf("<depth> : mettre à 0 si le solveur heuristique n'est pas utilisé. Valeur conseillée : tailleMat\n");
      exit(0);
  }
  float time;
  clock_t t1, t2;


  int n=atoi(argv[2]);



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

    if(!strcmp(argv[1],"-s")){


        printf("===> Recherche de toutes les solutions avec le solver simple :\n");

        t1 = clock();

        solver(colortemp, connextemp, p, n, &kmax, &nbiterate);

        t2 = clock();

        time = (float) (t2 - t1) / CLOCKS_PER_SEC;
        printf("Temps d'execution : %f secondes\n", time);

    }

    else if(!strcmp(argv[1],"-t")) {

        printf("===> Génération de l'arbre des solutions :\n");

        t1 = clock();


        solverTree(tree, col, con, n, atoi(argv[3]));


        t2 = clock();

        time = (float) (t2 - t1) / CLOCKS_PER_SEC;
        printf("Temps d'execution : %f secondes\n", time);

    }

    else if(!strcmp(argv[1],"-a")){
        printf("===> Recherche de toutes les solutions avec le solver simple :\n");

        t1 = clock();

        solver(colortemp, connextemp, p, n, &kmax, &nbiterate);

        t2 = clock();

        time = (float) (t2 - t1) / CLOCKS_PER_SEC;
        printf("Temps d'execution : %f secondes\n", time);

        printf("===> Génération de l'arbre des solutions :\n");

        t1 = clock();


        solverTree(tree, col, con, n, atoi(argv[3]));


        t2 = clock();

        time = (float) (t2 - t1) / CLOCKS_PER_SEC;
        printf("Temps d'execution : %f secondes\n", time);
    }

    else
        exit(1);



  freecolortable(col,n);
  freecolortable(colortemp,n);
  freeconnextab(connextemp,n);
  freeconnextab(con,n);
  freepile(p);


  return 0;
}
