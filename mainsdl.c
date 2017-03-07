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

SDL_Surface *initscreen(int n){
    SDL_Surface *screen=SDL_SetVideoMode(64*n+128,64*n+128, 32, SDL_HWSURFACE);
    if (SDL_Init(SDL_INIT_VIDEO)==-1){
        perror("SDL_INIT :");
        exit(EXIT_FAILURE);
    }
    SDL_WM_SetCaption("Colorflood : Les Pauseurs", "logo.png");

    return screen;
}

void updateCaseColor(char **colortable, SDL_Surface *colorcase, SDL_Surface *screen, int n) {
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

void TextOnScreen(SDL_Surface *screen, char *msg, char *font, SDL_Color color, SDL_Rect pos){
    SDL_Surface *txt;
    SDL_Color white={255,255,255,255};
    TTF_Font *txtfont;
    txtfont=TTF_OpenFont(font,28);
    if (txtfont==NULL){
        perror("Invalid Font");
        exit(EXIT_FAILURE);
    }

    txt=TTF_RenderText_Shaded(txtfont, msg, color, white);

    SDL_BlitSurface(txt, NULL, screen, &pos);
    SDL_Flip(screen);
    SDL_FreeSurface(txt);
    TTF_CloseFont(txtfont);
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


    SDL_Color txt_color={0,0,0,255};

    if(TTF_Init() == -1) {
        fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
        exit(EXIT_FAILURE);
    }

    char msg[64];
    SDL_Rect txtpos;
    txtpos.y=90+n*64;
    txtpos.x=16;
    /*===== Créations des Popups =====*/
    /*const SDL_MessageBoxButtonData buttons[]={{SDL_MESSAGEBOX_RETURNKEY_DEFAULT,0,"OK"}, {}};*/

    /*================================*/
    SDL_Event event;
    while(!wintest(connexetab, n) && color!='Q') {
        updateCaseColor(colortable, colorcase, screen, n);
        sprintf(msg,"Nombre de coups : %d/%d",k,kmax);
        TextOnScreen(screen, msg, "Xenotron.ttf", txt_color, txtpos);
        SDL_WaitEvent(&event);
        switch (event.type){
            case SDL_KEYDOWN :
                /**
                 * Premier switch : On appuie sur une touche ou pas
                 */
                switch(event.key.keysym.sym) {
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
    SDL_Quit();
    TTF_Quit();
    return 0;

}