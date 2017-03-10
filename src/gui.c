//
// Created by baron on 3/9/17.
//
#include "gui.h"


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

SDL_Surface *initscreen(){

    /*Récupération de la résolution dans setup.ini */
    int we,he;

    FILE* f = NULL;
    if((f = fopen("config.ini", "r")) == NULL){
        printf("Please launch ./setup.ini script\n");
        exit(1);
    }

    fscanf(f,"%dx%d", &we,&he);
    fclose(f);


    SDL_Surface *screen=SDL_SetVideoMode(we,he, 32, SDL_FULLSCREEN);
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

void updateCaseColor(char **colortable, SDL_Surface *colorcase, SDL_Surface *screen, int n,int off, int boardS, int squareS) {
    int i, j;
    SDL_Rect pos;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            pos.x= (screen->w-boardS)/2 + i * squareS;
            pos.y= off + j * squareS;
            if (colortable[i][j] == 'R') SDL_FillRect(colorcase, NULL, SDL_MapRGB(colorcase->format, 255, 0, 0));
            if (colortable[i][j] == 'V') SDL_FillRect(colorcase, NULL, SDL_MapRGB(colorcase->format, 0, 204, 0));
            if (colortable[i][j] == 'G') SDL_FillRect(colorcase, NULL, SDL_MapRGB(colorcase->format, 128, 128, 128));
            if (colortable[i][j] == 'M') SDL_FillRect(colorcase, NULL, SDL_MapRGB(colorcase->format, 102, 51, 0));
            if (colortable[i][j] == 'B') SDL_FillRect(colorcase, NULL, SDL_MapRGB(colorcase->format, 0, 0, 255));
            if (colortable[i][j] == 'J') SDL_FillRect(colorcase, NULL, SDL_MapRGB(colorcase->format, 255, 255, 0));
            SDL_BlitSurface(colorcase, NULL, screen, &pos);
        }
    }
    SDL_Flip(screen);
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

void BlackScreen(SDL_Surface *screen) {
    SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format, 0, 0, 0));
}


void HelpPage(SDL_Surface *screen,int n) {
    BlackScreen(screen);
    SDL_Event BackToGame;
    SDL_Rect helppos;

    while(!(SDL_KEYDOWN && SDLK_r))
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
