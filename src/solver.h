#include <stdio.h>
#include <stdlib.h>

#include "pile.h"
#include "datastruct.h"
#include "tree.h"


/**
 * @param colortable
 * @param color
 * @param connexetab
 * @param n
 * @return renvoie 1 si la couleur a un impact, 0 sinon
 */
int choixPertinent(char **colortable, char color, int **connexetab, int n);


/**
 * @param colortable
 * @param connexetab
 * @param solution
 * @param n
 * @return solver force brute qui affiche des solutions de plus en plus courtes
 * \brief ATTENTION LA FONCTION MODIFIE LES TAB PAR EFFET DE BORD 
 */

void solver(char **colortable, int **connexetab,pile *solution, int n,int *kmax, int *nbiterate);


void generateTree(char **colortable, int **connexetab, NTree tree, int n);

int heuristique(char **col, int** con, char color, int n);
