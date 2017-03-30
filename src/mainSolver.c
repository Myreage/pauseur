#include <stdlib.h>
#include <stdio.h>

#include "solver.h"
#include "pile.h"

#include "datastruct.h"
#include "colors.h"

int main(){
  fifo *p = malloc(sizeof(fifo*));
  p->length = 0;
  p->first = NULL;

  char **col = createcolortable(5);
  int **con = createconnexetab(5);


  fillcolortablerand(col,5);
  displaycolortable(col,5);

  /** COPIER LES TABLES KEK !!!! **/
  solveur(col,con,p,5);
  displayfifo(p);








  return 0;
}
