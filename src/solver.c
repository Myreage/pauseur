#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pile.h"
#include "datastruct.h"
#include "colors.h"
#include "solver.h"

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
        return 1;        /*s'il y a une modif, ok*/
      }
    }
  }
  return 0; /* sinon, pas pertinent */

}

int firstsolution(char **colortable, int **connexetab,fifo *solution, int n,int *kmax) {


  int i;
    char colors[6]={'B','V','R','J','M','G'};
    char** col;
    int** con;

  for (i=0; i<6; i++) { /* pour toutes les couleurs possibles */


    if (choixPertinent(colortable, colors[i], connexetab,n)) {

      thread(solution,colors[i]);  /* empile */

      if(solution->length <= *kmax){
        col = copycolortable(colortable,n);
        con = copyconnexetab(connexetab,n);

        updateconnexetab(col, con, colors[i], n);

        switchconnexecolors(col, con, colors[i], n);

        if (wintest(con,n)){
          *kmax = solution->length;
          printf("Solution trouvée : ");
          displayreversefifo(solution);
          printf(" en %d coups\n", *kmax);

        }

        else firstsolution(col,con,solution,n, kmax);
      }

      popfirst(solution);


    }

  }


}


/*fifo *solver(char **colortable, int **connexetab, fifo *firstsolution, int kmax, int n){

}*/
