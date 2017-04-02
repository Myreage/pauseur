#include <stdio.h>
#include <stdlib.h>

#include "pile.h"
#include "datastruct.h"


/**
 * @param colortable
 * @param color
 * @param connexetab
 * @param n
 * @return renvoie 1 si le couleur a un impact, 0 sinon
 */
int choixPertinent(char **colortable, char color, int **connexetab, int n);


/**
 * @param colortable
 * @param connexetab
 * @param solution
 * @param n
 * @return renvoie 1 et stocke la 1ere solution dans la pile solution, ou 0 si pas de sol
 * ATTENTION LA FONCTION MODIFIE LES TAB PAR EFFET DE BORD
 * UTILISER DES COPIES LORS DE L'APPEL !
 */
int solver(char **colortable, int **connexetab,pile *solution, int n,int *kmax, int *nbiterate);
