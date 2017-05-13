
#ifndef PAUSEUR_GUI_H
#define PAUSEUR_GUI_H


#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>

void TextOnScreenCenterX(SDL_Surface *screen, char *msg, char *font, char color, int fontsize, SDL_Rect pos);
/**
 * @return Renvoie un écran initialisé.
 **/
SDL_Surface *initscreen();

/**
 * @param colortable Matrice de couleur.
 * @param colorcase Case de couleur
 * @param screen Ecran
 * @param n Taille du board
 * @param off Offset en pixels
 * @param boardS Taille du board en pixels
 * @param squareS Taille d'une case en pixels
 * \brief Met à jour les couleurs affichées
 **/
void updateCaseColor(char **colortable, SDL_Surface *colorcase, SDL_Surface *screen, int n,int off, int boardS, int squareS);

/**
 * @param screen Ecran
 * @param msg Texte à écrire
 * @param font Police d'écriture
 * @param color Couleur d'écriture
 * @param fontsize Taille d'écriture
 * @param pos Position sur l'écran
 * \brief Ecrit du texte à l'écran, avec la police, position et taille choisi.
 **/
void TextOnScreen(SDL_Surface *screen, char *msg, char *font, char color, int fontsize, SDL_Rect pos);

/**
 * @param screen Ecran
 * @return Renvoit le gamestate
 * \brief Gestion et affichage de la page d'aide
 **/
int HelpPage(SDL_Surface *screen);

/**
 * @param screen Ecran
 * Colore l'écran en noir (pour réinitialiser l'affichage)
 **/
void BlackScreen(SDL_Surface *screen);

/**
 * @param screen Ecran
 * @return Renvoit le gamestate
 * \brief Gestion et affichage de la page d'accueil
 **/
char HomePage(SDL_Surface *screen);

/**
 * @param screen Ecran
 * @param n Taille du board
 * @param color Couleur jouée
 * @param kmax Nombre de coups max
 * @param colortable Matrice Couleur
 * @param connexetab Matrice connexité
 * @param colorcase Case
 * @return Renvoie le gamestate
 * \brief Gestion de la partie de jeu
 **/
int GameLoop(SDL_Surface *screen, int n, char color, int kmax, char **colortable, int **connexetab, SDL_Surface *colorcase);

/**
 * @param screen Ecran
 * @return Renvoie le gamestate
 **/
int LooseScreen(SDL_Surface *screen);

/**
 * @param screen Ecran
 * @return Renvoie le gamestate
 **/
int VictoryScreen(SDL_Surface *screen);


/**
 * Différenciation faite entre l'écran de victoire et de défaite pour la simplifier un ajout potentiel d'animation
 **/

 void SearchingSolution(SDL_Surface *screen);
#endif //PAUSEUR_GUI_H
