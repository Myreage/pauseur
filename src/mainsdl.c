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

    int exitcond=0;
    int gamestate=0;

    while(!exitcond){
        switch(gamestate){
            case 0:
                gamestate=HomePage(screen);
                break;
            case 1:
                gamestate=GameLoop(screen,n,color,kmax,colortable,connexetab,colorcase);
                break;
            case 2:
                gamestate=HelpPage(screen, n);
                break;
            /*case 3:
                gamestate=VictoryScreen();
                break;
            case 4:
                gamestate=LoseScreen();
                break;*/
            case 5:
                exitcond=1;
                break;
        }
    }


    SDL_FreeSurface(colorcase);
    SDL_FreeSurface(screen);
    freecolortable(colortable,n);
    freeconnextab(connexetab,n);
    SDL_Quit();
    TTF_Quit();
    return 0;

}
