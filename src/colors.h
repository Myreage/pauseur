#ifndef COLORS_H
#define COLORS_H

/**
 * @param Matrice de connexité.
 * @param n taille du tableau.
 * @return Test de la condition de victoire : si un élèment de la matrice de connexité est nul, renvoie 0, sinon, renvoie 1.
 */
int wintest(int **connexetab, int n);

/**
 *@param connexetab
 * @param x coordonnée du point
 * @param y coordonnée du point
 * @param n taille du tableau
 * @return renvoie 1 si la case selectionée en (x,y) fait parti de la composante connexe.
 */
int isconnexe(int **connexetable, int x, int y, int n);

/**
 *
 * @param colortable Tableau de couleur
 * @param connexetab Matrice de connexité
 * @param color Couleur séléctionnée
 * @param n taille du tableau
 * Met à jour la matrice de connexité en fonction de la couleur entrée en paramètre.
 */
void updateconnexetab(char **colortable, int **connexetab, char color, int n);

/**
 *
 * @param colortable Tableau de couleur
 * @param connexetab Matrice de connexité
 * @param color Couleur séléctionnée
 * @param n taille du tableau
 *
 * Change la couleurs de toutes les cases de la composante connexe par la couleur souhaitée.
 *
 */
void switchconnexecolors(char **colortable, int **connexetab, char color, int n);
#endif
