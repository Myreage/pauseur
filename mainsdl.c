#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include "datastruct.h"
#include "colors.h"
#include <SDL/SDL.h>


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
    SDL_WM_SetCaption("Colorflood : Les Pauseurs", NULL);

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


/* RGB Color Code :
 * "R" (255,0,0)
 * "V" (0,204,0)
 * "G" (128,128,128)
 * "B" (0,0,255)
 * "M" (102,51,0)
 * "J" (255,255,0)
 * */

int main(){
    int n=6;
    char **colortable=createcolortable(n);
    fillcolortablerand(colortable, n);
    int **connexetab=createconnexetab(n);
    char color=colortable[0][0];
    updateconnexetab(colortable, connexetab, color, n);

    int k=0;

    SDL_Surface *colorcase=NULL;
    colorcase=SDL_CreateRGBSurface(0,64,64,32,0,0,0,0);

    SDL_Surface *screen=initscreen(n);

    SDL_Event event;
    while(!wintest(connexetab, n)) {
        updateCaseColor(colortable, colorcase, screen, n);
        SDL_WaitEvent(&event);
        switch (event.type){
            case SDL_KEYDOWN :
                switch(event.key.keysym.sym) {
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
                    default :
                        break;
                }
            default :
                break;

        }
        updateconnexetab(colortable, connexetab, color, n);
        switchconnexecolors(colortable, connexetab, color, n);
    }
    SDL_FreeSurface(colorcase);
    SDL_FreeSurface(screen);
    SDL_Quit();
    return 0;

}