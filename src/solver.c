#include <stdio.h>
#include <stdlib.h>

#include "solver.h"
#include "pile.h"
#include "datastruct.h"
#include "colors.h"

int choixPertinent(char **colortable, char color, int **connexetab, int n){
  int i,j;
  int **aux = createconnexetab(n);

  for(i=0;i<n;i++){   /*copie de la connexetab*/
    for(j=0;j<n;j++){
      aux[i][j] = connexetab[i][j];
    }
  }

  updateconnexetab(colortable, aux, color, n);

  for(i=0;i<n;i++){   /*comparaison des tables*/
    for(j=0;j<n;j++){
      if(aux[i][j] != connexetab[i][j]){
        return 1;        /*s'il y a une modif, ok*/
      }
    }
  }
  return 0; /*sinon, pas pertinent*/

}

int solveur(char **colortable, int **connexetab, fifo *solution, int n) {

  int i;
  char colors[6]={'B','V','R','J','M','G'};
  for (i=0; i<6; i++) { // pour toutes les couleurs possibles
    printf("Couleur : %c", colors[i]);
    if (choixPertinent(colortable, colors[i], connexetab,n)) {
      printf("choix pertinent\n");
      thread(solution,colors[i]);  /*empile*/
      updateconnexetab(colortable, connexetab, colors[i], n);
      switchconnexecolors(colortable, connexetab, colors[i], n);
      if (wintest(connexetab,n)) return 1;
      else solveur(colortable,connexetab,solution,n);
      popfirst(solution);
    }
    else printf("choix non pertinent\n");
  }
  return 0;
}
