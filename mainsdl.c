#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include "datastruct.h"
#include "colors.h"
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>

#include "gui.h"



/*------****Menu positions--***------*/
/* L'écran est coupé en 100 colonnes */
#define TITLEPOS (float)38/100
#define STARTPOS (float)20/100
#define CONTROLSPOS (float)45/100
#define QUITPOS (float)80/100

/*------****Game positions--***------*/
/* L'écran est coupé en 100 colonnes */
#define SCOREPOSH (float)95/100
#define SCOREPOSW (float)40/100

/*Offset vertical*/
#define OFF 10/100


/**
 * Explications : La fenêtre crée peut se ramener a une matrice de taille n+1
 * de carrés de 64x64 pixels.
 * La surface colorcase est de manière imagée, un tampon de 64x64 pixels dont on peut
 * choisir la couleur et la position.
 * Une fois ces paramètres ajustés, on tamponne sur la fenetre avec la fonction : SDL_Blit_Surface
 * et on met a jour l'écran grâce à SDL_Flip.
 */


int main(int argc, char *argv[]){
    if (argc<2){
        printf("Deux arguments nécéssaires : Taille de la Grille et Nombre de Coups\n");
        exit(0);
    }

    int n=atoi(argv[1]);
    int kmax=atoi(argv[2]);
    printf("%d\n", n);
    char **colortable=createcolortable(n);
    fillcolortablerand(colortable, n);
    int **connexetab=createconnexetab(n);
    char color=colortable[0][0];
    updateconnexetab(colortable, connexetab, color, n);

    SDL_Surface *screen=initscreen();

    /*-----Params de placement-----*/
    int off = screen->h*OFF;
    int boardS = screen->h - 2*off; /*taille d'un coté du board*/
    int squareS = boardS/n; /*taille du côté d'un carré*/


    int k=0;

    SDL_Surface *colorcase=NULL;
    colorcase=SDL_CreateRGBSurface(0,squareS,squareS,32,0,0,0,0);






    /*===== Créations des Popups =====*/
    /*const SDL_MessageBoxButtonData buttons[]={{SDL_MESSAGEBOX_RETURNKEY_DEFAULT,0,"OK"}, {}};*/

    /*================================*/
    /**
     * Affichage du Menu
     */

    SDL_Event move;
    int actualpos=0;
    SDL_Surface *menuimg=IMG_Load("drowncube.jpg");

    SDL_Rect menupos;
    SDL_BlitSurface(menuimg, NULL, screen, &menupos);

    menupos.x=screen->w*TITLEPOS;
    menupos.y=screen->h/10;
    TextOnScreen(screen, "Colorflood", "Xenotron.ttf", 'W', 40, menupos);


    menupos.y=screen->h/2;
    menupos.x=screen->w*STARTPOS;


    TextOnScreen(screen, "Start", "Xenotron.ttf", 'G', 20, menupos);

    menupos.x=screen->w*CONTROLSPOS;
    TextOnScreen(screen, "Controles", "Xenotron.ttf", 'W', 20, menupos);

    menupos.x=screen->w*QUITPOS;
    TextOnScreen(screen, "Quitter", "Xenotron.ttf", 'W', 20, menupos);
    /**
     * Afficher les autres champs avec avec la couleur blanche : Controlles et Quitter
     */
    int exitcond=0;
    while(!exitcond) {
        SDL_WaitEvent(&move);
        switch (move.type) {
            case SDL_KEYDOWN :
                switch (move.key.keysym.sym) {
                    case SDLK_LEFT :
                        if (actualpos == 0) {
                            menupos.x=screen->w*STARTPOS;

                            TextOnScreen(screen, "Start", "Xenotron.ttf", 'W', 20, menupos);

                            menupos.x=screen->w*CONTROLSPOS;
                            TextOnScreen(screen, "Controles", "Xenotron.ttf", 'W', 20, menupos);

                            menupos.x=screen->w*QUITPOS;
                            TextOnScreen(screen, "Quitter", "Xenotron.ttf", 'G', 20, menupos);
                            actualpos = 2;
                            break;
                        }
                        else if (actualpos == 1) {
                            menupos.x=screen->w*STARTPOS;

                            TextOnScreen(screen, "Start", "Xenotron.ttf", 'G', 20, menupos);

                            menupos.x=screen->w*CONTROLSPOS;
                            TextOnScreen(screen, "Controles", "Xenotron.ttf", 'W', 20, menupos);

                            menupos.x=screen->w*QUITPOS;
                            TextOnScreen(screen, "Quitter", "Xenotron.ttf", 'W', 20, menupos);
                            actualpos = 0;
                            break;
                        }
                        else if (actualpos == 2) {
                            menupos.x=screen->w*STARTPOS;

                            TextOnScreen(screen, "Start", "Xenotron.ttf", 'W', 20, menupos);

                            menupos.x=screen->w*CONTROLSPOS;
                            TextOnScreen(screen, "Controles", "Xenotron.ttf", 'G', 20, menupos);

                            menupos.x=screen->w*QUITPOS;
                            TextOnScreen(screen, "Quitter", "Xenotron.ttf", 'W', 20, menupos);
                            actualpos = 1;
                            break;
                        }

                    case SDLK_RIGHT :
                        if (actualpos == 0) {
                            menupos.x=screen->w*STARTPOS;

                            TextOnScreen(screen, "Start", "Xenotron.ttf", 'W', 20, menupos);

                            menupos.x=screen->w*CONTROLSPOS;
                            TextOnScreen(screen, "Controles", "Xenotron.ttf", 'G', 20, menupos);

                            menupos.x=screen->w*QUITPOS;
                            TextOnScreen(screen, "Quitter", "Xenotron.ttf", 'W', 20,menupos);
                            actualpos = 1;
                            break;
                        }
                        else if (actualpos == 1) {
                            menupos.x=screen->w*STARTPOS;

                            TextOnScreen(screen, "Start", "Xenotron.ttf", 'W', 20,menupos);

                            menupos.x=screen->w*CONTROLSPOS;
                            TextOnScreen(screen, "Controles", "Xenotron.ttf", 'W', 20, menupos);

                            menupos.x=screen->w*QUITPOS;
                            TextOnScreen(screen, "Quitter", "Xenotron.ttf", 'G', 20,menupos);
                            actualpos = 2;
                            break;
                        }
                        else if (actualpos == 2) {
                            menupos.x=screen->w*STARTPOS;

                            TextOnScreen(screen, "Start", "Xenotron.ttf", 'G', 20,menupos);

                            menupos.x=screen->w*CONTROLSPOS;
                            TextOnScreen(screen, "Controles", "Xenotron.ttf", 'W', 20, menupos);

                            menupos.x=screen->w*QUITPOS;
                            TextOnScreen(screen, "Quitter", "Xenotron.ttf", 'W', 20,menupos);
                            actualpos = 0;
                            break;
                        }

                    case SDLK_RETURN :
                        if (actualpos == 0) {
                            exitcond=1;
                            break;
                        }
                        else if (actualpos == 1) {
                            /**
                             * Afficher le menu des Options
                             */

                        }
                        else if (actualpos == 2) {
                            color='Q';
                            exitcond=1;
                            break;
                        }
                    default :
                        break;

                }
            default :
                break;
        }
    }

    SDL_FreeSurface(menuimg);







    /**
     * Boucle de Jeu
     */



    SDL_Event keyevent;

    char msgCount[64];
    SDL_Rect txtpos;
    txtpos.y=screen->h*SCOREPOSH;
    txtpos.x=screen->w*SCOREPOSW;

    while(!wintest(connexetab, n) && color!='Q' && k<kmax) {
        updateCaseColor(colortable, colorcase, screen, n,off,boardS,squareS);

        if (k%10==1) {
            sprintf(msgCount, "Nombre de coup :  %d/%d ",k, kmax);
        }
        else {
            sprintf(msgCount, "Nombre de coup : %d/%d ", k, kmax);
        }

        TextOnScreen(screen, msgCount,"Xenotron.ttf", color, 20,txtpos);
        SDL_WaitEvent(&keyevent);

        /**
         * Mettre l'event j'appuie sur une touche dans un fonction
         */

        switch (keyevent.type){
            case SDL_KEYDOWN :
                /**
                 * Premier switch : On appuie sur une touche ou pas
                 */
                switch(keyevent.key.keysym.sym) {
                    /**
                     * Second switch : Si on appuie sur une touche, et que cette touche est R,V,B,J,G, ou M, on change la couleur.
                     */
                    case SDLK_r :
                        color = 'R';
                        k++;
                        break;
                    case SDLK_v :
                        color = 'V';
                        k++;
                        break;
                    case SDLK_b :
                        color = 'B';
                        k++;
                        break;
                    case SDLK_g :
                        color = 'G';
                        k++;
                        break;
                    case SDLK_j :
                        color = 'J';
                        k++;
                        break;
                    case SDLK_m :
                        color = 'M';
                        k++;
                        break;
                    case SDLK_q:
                        color='Q';
                    default :
                        break;
                }
            default :
                break;

        }
        SDL_FreeSurface(screen);
        updateconnexetab(colortable, connexetab, color, n);
        switchconnexecolors(colortable, connexetab, color, n);
    }
    SDL_FreeSurface(colorcase);
    SDL_FreeSurface(screen);
    freecolortable(colortable,n);
    freeconnextab(connexetab,n);
    SDL_Quit();
    TTF_Quit();
    return 0;

}
