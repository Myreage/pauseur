#ifndef DATASTRUCT_H
#define DATASTRUCT_H

/**
 * @param n taille du tableau.
 * @return renvoie une Matrice de couleur initialisée de taille n.
 */
char** createcolortable(int n);

/**
 * @param n taille du tableau.
 * @return renvoie une Matrice de connexité initialisée de taille n : : Elle a pour but de marquer les cases qui appartiennent à la composante connexe.
 * \brief Contient un 1 si la cases est dans la composante connexe, 0 sinon.
 */
int **createconnexetab(int n);

/**
 * @param connextab
 * @param n
 * @return une copie de la matrice de connexité
 */
int **copyconnexetab(int **connextab, int n);

/**
 * @param connextab
 * @param n
 * @return une copie de la Matrice de couleur
 */
char **copycolortable(char **colortable, int n);
/**
* @param colortable Matrice de couleur
* @param n taille de la matrice de couleur.
* \brief Libère l'espace mémoire attribué à la matrice de couleur
*/
void freecolortable(char **colortable, int n);

/**
 *@param connextab Matrice de connexité
 * @param n taille de la matrice de connexité
 * \brief Libère l'espace mémoire attribu à la matrice de connexité.
 */
void freeconnextab(int **connextab, int n);

/**
 *@param colortable Matrice de couleur
 * @param n taille de la matrice de couleur
 * \brief Rempli une matrice de couleur aléatoirement à partir des valeures autorisées.
 */
void fillcolortablerand(char **colortable, int n);

/**
 * @param colortable matrice de couleur
 * @param n taille de la matrice de couleur
 * @param filename nom du fichier
 * \brief Rempli une matrice de couleur à partir d'un fichier. L'entrée attendu est un fichier conforme aux règles du jeux, c'est à dire ne contenant que les couleures autorisées, n lignes et n colonnes, sans espaces.
 */
void fillcolortablefile(char **colortable, int n, char *filename);

/**
 *
 * @param filename nom du fichier à créer.
 * @param n taille de la matrice crée dans le fichier.
 * \brief Génère un fichier de couleur aléatoire, conforme aux conditions d'entrée de la fonction de remplissage de la table de couleur à partir d'un fichier.
 */
void createnewcolorfile(char *name, int n);

/**
 *@param colortable matrice de couleur
 * @param color nouvelle couleur de la case
 * @param x coordonnée du point
 * @param y coordonnée du point
 *
 * \brief Change la couleur de la case (x,y) par la couleur entrée en paramètre.
 */
void switchcolor(char **colortable, char color, int x, int y);

/**
 *@param colortable matrice de couleur
 * @param n Taille de la matrice de couleur
 * \brief Affiche la matrice de couleur entrée en paramètre.
 */
void displaycolortable(char **colortable, int n);

/**
 *
 * @param tab matrice de connexité
 * @param n taille de la matrice de conexité
 * \brief Affiche la matrice de connexité.
 */
void displayconnexetab(int **connexetab, int n);


#endif
