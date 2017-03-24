#include <stdio.h>
#include <stdlib.h>

#include "pile.h"
#include "datastruct.h"

int choixPertinent(char **colortable, char color); /*renvoie 1 si la couleur est pertinente à jouer */
void solver(colortable t, pile solution);
