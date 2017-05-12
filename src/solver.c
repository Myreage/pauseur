#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pile.h"
#include "datastruct.h"
#include "colors.h"
#include "solver.h"
#include "tree.h"

#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define RESET "\x1B[0m"



int choixPertinent(char **colortable, char color, int **connexetab, int n){
  int i,j;
  int **aux = createconnexetab(n);

  for(i=0;i<n;i++){   /*copie de la connexetab*/
    for(j=0;j<n;j++){
      aux[i][j] = connexetab[i][j];
    }
  }

  updateconnexetab(colortable, aux, color, n);

  for(i=0;i<n;i++){   /* comparaison des tables */
    for(j=0;j<n;j++){
      if(aux[i][j] != connexetab[i][j]){
        freeconnextab(aux,n);
        return 1;        /*s'il y a une modif, ok*/
      }
    }
  }
  freeconnextab(aux,n);
  return 0; /* sinon, pas pertinent */

}


void solver(char **colortable, int **connexetab,pile *solution, int n,int *kmax,int *nbiterate) {


  int i;
  *nbiterate = *nbiterate + 1;

  char colors[6]={'B','V','R','J','M','G'};
  char** col;
  int** con;

  for (i=0; i<6; i++) { /* pour toutes les couleurs possibles */


    if (choixPertinent(colortable, colors[i], connexetab,n)) {

      stack(solution,colors[i]);  /* empile */

      if(solution->length < *kmax){
        col = copycolortable(colortable,n);
        con = copyconnexetab(connexetab,n);

        updateconnexetab(col, con, colors[i], n);

        switchconnexecolors(col, con, colors[i], n);


        if (wintest(con,n)){
          *kmax = solution->length;
          printf("Solution trouvée : ");
          displayreversepile(solution);
          printf(" en %d coups", *kmax);
          printf(" en %d itérations\n", *nbiterate);


        }

        else solver(col,con,solution,n, kmax,nbiterate);

        freeconnextab(con,n);
        freecolortable(col,n);
      }

      pop(solution);



    }

  }

}

void generateTree(NTree tree, NTree arbremax, char **colortable, int **connexetab, int n, int depth, int *hmax){

    if(depth && !wintest(connexetab,n) ){
        char colors[6]={'B','V','R','J','M','G'};
        char** col;
        int** con;
        int i;
        NTree child = NULL;

        for(i=0;i<6;i++){
            if(choixPertinent(colortable,colors[i],connexetab,n)){
                col = copycolortable(colortable, n);
                con = copyconnexetab(connexetab, n);
                updateconnexetab(col, con, colors[i], n);
                switchconnexecolors(col, con, colors[i], n);

                child = newTree(col,con,wintest(con,n),colors[i]);
                tree = addChild(tree,child);

                generateTree(child,arbremax,col,con,n,depth-1,hmax);


            }
        }
    }
    else{

        if(heuristique(connexetab,n) > *hmax) {
            *hmax = heuristique(connexetab, n);
            arbremax = tree;
            printTree(arbremax,0);
            printf("***\n");
        }
    }

    /*if(!wintest(arbremax->con,n)){
        *hmax = 0;
        generateTree(arbremax,NULL,colortable,connexetab,n,depth,hmax);
    }*/

}


int heuristique(int** connext, int n){
  int i,j;
  int total=0;


  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
        total+=connext[i][j];
    }
  }

  return total;

}




