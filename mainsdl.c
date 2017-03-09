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

/**
 * Explications : La fenêtre crée peut se ramener a une matrice de taille n+1
 * de carrés de 64x64 pixels.
 * La surface colorcase est de manière imagée, un tampon de 64x64 pixels dont on peut
 * choisir la couleur et la position.
 * Une fois ces paramètres ajustés, on tamponne sur la fenetre avec la fonction : SDL_Blit_Surface
 * et on met a jour l'écran grâce à SDL_Flip.
 */
void SDLwait() {
    int continuer = 1;
    SDL_Event event;
    while (continuer) {
        SDL_WaitEvent(&event);
        switch(event.type) {
            case SDL_QUIT:
                continuer = 0;
        }
    }
}

void BlackScreen(SDL_Surface *screen)
{
  SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format, 0, 0, 0));
}

SDL_Surface *initscreen(int n){
    SDL_Surface *screen=SDL_SetVideoMode(64*n+128,64*n+128, 32, SDL_HWSURFACE);
    if (SDL_Init(SDL_INIT_VIDEO)==-1){
        perror("SDL_INIT :");
        exit(EXIT_FAILURE);
    }
    if (IMG_Init(IMG_INIT_JPG)==-1){
        perror("IMG_INIT :");
        exit(EXIT_FAILURE);
    }
    if(TTF_Init() == -1) {
        fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
        exit(EXIT_FAILURE);
    }
    SDL_WM_SetCaption("Colorflood : Les Pauseurs", "logo.png");

    return screen;
}

void updateCaseColor(char **colortable, SDL_Surface *colorcase, SDL_Surface *screen, int n) {
    BlackScreen(screen);
    int i, j;
    SDL_Rect pos;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            pos.x= 64 + i * 64;
            pos.y= 64 + j * 64;
            if (colortable[i][j] == 'R') SDL_FillRect(colorcase, NULL, SDL_MapRGB(colorcase->format, 255, 0, 0));
            if (colortable[i][j] == 'V') SDL_FillRect(colorcase, NULL, SDL_MapRGB(colorcase->format, 0, 204, 0));
            if (colortable[i][j] == 'G') SDL_FillRect(colorcase, NULL, SDL_MapRGB(colorcase->format, 128, 128, 128));
            if (colortable[i][j] == 'M') SDL_FillRect(colorcase, NULL, SDL_MapRGB(colorcase->format, 102, 51, 0));
            if (colortable[i][j] == 'B') SDL_FillRect(colorcase, NULL, SDL_MapRGB(colorcase->format, 0, 0, 255));
            if (colortable[i][j] == 'J') SDL_FillRect(colorcase, NULL, SDL_MapRGB(colorcase->format, 255, 255, 0));
            SDL_BlitSurface(colorcase, NULL, screen, &pos);
        }
        SDL_Flip(screen);
    }
}

void TextOnScreen(SDL_Surface *screen, char *msg, char *font, char color, int fontsize, SDL_Rect pos){
    TTF_Font *txtfont;
    SDL_Surface *txt;
    txtfont=TTF_OpenFont(font,fontsize);

    if (txtfont==NULL){
        perror("Invalid Font");
        exit(EXIT_FAILURE);
    }
    SDL_Color colorR = {255,0,0,0};
    SDL_Color colorG = {128,128,128,0};
    SDL_Color colorV = {0,204,0,0};
    SDL_Color colorB = {0,0,255,0};
    SDL_Color colorJ = {255,255,0,0};
    SDL_Color colorM = {102,51,0,0};
    SDL_Color black={0,0,0,0};
    SDL_Color white={255,255,255,0};

    switch (color) {
        case 'R' :
            txt=TTF_RenderText_Shaded(txtfont, msg, colorR,black);
            break;
        case 'G' :
            txt=TTF_RenderText_Shaded(txtfont, msg, colorG,black);
            break;
        case 'V' :
            txt=TTF_RenderText_Shaded(txtfont, msg, colorV,black);
            break;
        case 'B' :
            txt=TTF_RenderText_Shaded(txtfont, msg, colorB,black);
            break;
        case 'J' :
            txt=TTF_RenderText_Shaded(txtfont, msg, colorJ,black);
            break;
        case 'M' :
            txt=TTF_RenderText_Shaded(txtfont, msg, colorM,black);
            break;
        case 'W' :
            txt=TTF_RenderText_Shaded(txtfont, msg, white, black);
        default :
            break;
    }

    SDL_BlitSurface(txt, NULL, screen, &pos);
    SDL_Flip(screen);
    TTF_CloseFont(txtfont);
    SDL_FreeSurface(txt);
}

void HelpPage(SDL_Surface *screen,int n)
{
  BlackScreen(screen);
  SDL_Event BackToGame;

  SDL_Rect helppos;

  int b = 0;

  while(b==0)
  {

    helppos.x=32*n+64-210;
    helppos.y=64;
    TextOnScreen(screen, "Pour jouer, pressez ", "Xenotron.ttf", 'W', 25, helppos);
    helppos.y=84;
    TextOnScreen(screen, "une touche :", "Xenotron.ttf", 'W', 25, helppos);
    helppos.y=124;
    TextOnScreen(screen, "r pour jouer rouge", "Xenotron.ttf", 'W', 20, helppos);
    helppos.y=144;
    TextOnScreen(screen, "b pour jouer bleu", "Xenotron.ttf", 'W', 20, helppos);
    helppos.y=164;
    TextOnScreen(screen, "m pour jouer marron", "Xenotron.ttf", 'W', 20, helppos);
    helppos.y=184;
    TextOnScreen(screen, "g pour jouer gris", "Xenotron.ttf", 'W', 20, helppos);
    helppos.y=204;
    TextOnScreen(screen, "j pour jouer jaune", "Xenotron.ttf", 'W', 20, helppos);
    helppos.y=224;
    TextOnScreen(screen, "v pour jouer vert", "Xenotron.ttf", 'W', 20, helppos);
    helppos.y=244;
    TextOnScreen(screen, "q pour quitter la partie", "Xenotron.ttf", 'W', 20, helppos);
    helppos.y=284;
    TextOnScreen(screen, "Pressez R pour", "Xenotron.ttf", 'W', 25, helppos);
    helppos.y=304;
    TextOnScreen(screen, "revenir a la partie.", "Xenotron.ttf", 'W', 25, helppos);




    SDL_WaitEvent(&BackToGame);
    switch (BackToGame.type)
    {
        case SDL_KEYDOWN :
            switch(BackToGame.key.keysym.sym)
            {
                case SDLK_r :
                    b = 1;
                    break;
                default :
                    break;
            }
        default :
            break;
    }
  }
}



/* RGB Color Code :
 * "R" (255,0,0)
 * "V" (0,204,0)
 * "G" (128,128,128)
 * "B" (0,0,255)
 * "M" (102,51,0)
 * "J" (255,255,0)
 * */



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

    int k=0;

    SDL_Surface *colorcase=NULL;
    colorcase=SDL_CreateRGBSurface(0,64,64,32,0,0,0,0);

    SDL_Surface *screen=initscreen(n);

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

    menupos.x=32*(n+1)-100;
    menupos.y=32*(n+1)-162;
    SDL_BlitSurface(menuimg, NULL, screen, &menupos);

    menupos.x=32*n+64-210;
    menupos.y=64;
    TextOnScreen(screen, "Colorflood", "Xenotron.ttf", 'W', 40, menupos);


    menupos.y=n*64;
    menupos.x=10*n-10;


    TextOnScreen(screen, "Start", "Xenotron.ttf", 'G', 20, menupos);

    menupos.x=32*n-20;
    TextOnScreen(screen, "Controles", "Xenotron.ttf", 'W', 20, menupos);

    menupos.x=64*n;
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
                            menupos.x=10*n;

                            TextOnScreen(screen, "Start", "Xenotron.ttf", 'W', 20, menupos);

                            menupos.x=32*n-26;
                            TextOnScreen(screen, "Controles", "Xenotron.ttf", 'W', 20, menupos);

                            menupos.x=64*n-70;
                            TextOnScreen(screen, "Quitter", "Xenotron.ttf", 'G', 20, menupos);
                            actualpos = 2;
                            break;
                        }
                        else if (actualpos == 1) {
                            menupos.x=10*n;

                            TextOnScreen(screen, "Start", "Xenotron.ttf", 'G', 20, menupos);

                            menupos.x=32*n-26;
                            TextOnScreen(screen, "Controles", "Xenotron.ttf", 'W', 20, menupos);

                            menupos.x=64*n-70;
                            TextOnScreen(screen, "Quitter", "Xenotron.ttf", 'W', 20, menupos);
                            actualpos = 0;
                            break;
                        }
                        else if (actualpos == 2) {
                            menupos.x=10*n;

                            TextOnScreen(screen, "Start", "Xenotron.ttf", 'W', 20, menupos);

                            menupos.x=32*n-26;
                            TextOnScreen(screen, "Controles", "Xenotron.ttf", 'G', 20, menupos);

                            menupos.x=64*n-70;
                            TextOnScreen(screen, "Quitter", "Xenotron.ttf", 'W', 20, menupos);
                            actualpos = 1;
                            break;
                        }

                    case SDLK_RIGHT :
                        if (actualpos == 0) {
                            menupos.x=10*n;

                            TextOnScreen(screen, "Start", "Xenotron.ttf", 'W', 20, menupos);

                            menupos.x=32*n-26;
                            TextOnScreen(screen, "Controles", "Xenotron.ttf", 'G', 20, menupos);

                            menupos.x=64*n-70;
                            TextOnScreen(screen, "Quitter", "Xenotron.ttf", 'W', 20,menupos);
                            actualpos = 1;
                            break;
                        }
                        else if (actualpos == 1) {
                            menupos.x=10*n;

                            TextOnScreen(screen, "Start", "Xenotron.ttf", 'W', 20,menupos);

                            menupos.x=32*n-26;
                            TextOnScreen(screen, "Controles", "Xenotron.ttf", 'W', 20, menupos);

                            menupos.x=64*n-70;
                            TextOnScreen(screen, "Quitter", "Xenotron.ttf", 'G', 20,menupos);
                            actualpos = 2;
                            break;
                        }
                        else if (actualpos == 2) {
                            menupos.x=10*n;

                            TextOnScreen(screen, "Start", "Xenotron.ttf", 'G', 20,menupos);

                            menupos.x=32*n-26;
                            TextOnScreen(screen, "Controles", "Xenotron.ttf", 'W', 20, menupos);

                            menupos.x=64*n-70;
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


    /**
     * Boucle de Jeu
     */

    SDL_Event keyevent;

    char msgCount[64];
    SDL_Rect txtpos;
    txtpos.y=90+n*64;
    txtpos.x=32*n-100;

    while(!wintest(connexetab, n) && color!='Q') {
        updateCaseColor(colortable, colorcase, screen, n);

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
                    case SDLK_h :
                        HelpPage(screen,n);
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
    SDL_Quit();
    TTF_Quit();
    return 0;

}
