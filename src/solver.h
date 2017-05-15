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

/**
 *
 * @param tree arbre à générer
 * @param colortable table de couleurs
 * @param connexetab table de connexité
 * @param n dimension des tables
 * @param depth profondeur de génération de l'arbre
 */

void aux(NTree tree, char **colortable, int **connexetab, int n, int depth);

/**
 *
 * @param tree arbre à explorer
 * @param n dimension des tables
 * @return noeud d'heuristique maximale
 */
NTree maxNode(NTree tree, int n);

/**
 *
 * @param colortable table initiale
 * @param connexetab table initiale
 * @param n dimension des tables
 * @param depth profondeur de génération de la fonction aux
 */
pile *solverTree(char **colortable, int **connexetab, int n, int depth);

/**
 *
 * @param con table de connexité
 * @param n dimension de la table
 * @return nombre d'élements dans la tâche de connexité
 */
int heuristique(int** con, int n);
