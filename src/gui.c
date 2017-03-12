#include "gui.h"
#include <time.h>

/** Path de la police **/

#define FONT_PATH "design/Xenotron.ttf"

/** Path logo **/
#define IMG_PATH "design/drowncube.jpg"


/** Position horizontale menu **/
#define MENUPOS (float)80/100

/** Position horizontale logo **/
#define LOGOPOSH (float)50/100

/** Position verticale Logo **/
#define LOGOPOSW (float)50/100

/** Position verticale Titre **/
#define TITLEPOS (float)36/100

/** Position verticale bouton Start **/
#define STARTPOS (float)20/100

/** Position verticale bouton Controls **/
#define CONTROLSPOS (float)45/100

/** Position verticale bouton Quit **/
#define QUITPOS (float)80/100

/** Position horizontale du score **/
#define SCOREPOSH (float)95/100

/** Position verticale du score **/
#define SCOREPOSW (float)40/100

/** Position verticale help page **/
#define HELPPOSW (float) 36/100

/** Offset vertical**/
#define OFF 10/100


SDL_Surface *initscreen(){

    /*Récupération de la résolution dans setup.ini */
    int we,he;

    FILE* f = NULL;
    if((f = fopen("config.ini", "r")) == NULL){
        printf("Please launch ./setup.ini (for MS Windows users : refer to documentation) \n");
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



int HelpPage(SDL_Surface *screen) {
    BlackScreen(screen);
    SDL_Event BackToGame;
    SDL_Rect helppos;


    while(!((BackToGame.type==SDL_KEYDOWN) && (BackToGame.key.keysym.sym==SDLK_r)))    {


        helppos.x=screen->w*HELPPOSW;
        helppos.y=64;
        TextOnScreen(screen, "Pour jouer, pressez ", FONT_PATH, 'W', 25, helppos);
        helppos.y=84;
        TextOnScreen(screen, "une touche :", FONT_PATH, 'W', 25, helppos);
        helppos.y=124;
        TextOnScreen(screen, "r pour jouer rouge", FONT_PATH, 'W', 20, helppos);
        helppos.y=144;
        TextOnScreen(screen, "b pour jouer bleu", FONT_PATH, 'W', 20, helppos);
        helppos.y=164;
        TextOnScreen(screen, "m pour jouer marron", FONT_PATH, 'W', 20, helppos);
        helppos.y=184;
        TextOnScreen(screen, "g pour jouer gris", FONT_PATH, 'W', 20, helppos);
        helppos.y=204;
        TextOnScreen(screen, "j pour jouer jaune", FONT_PATH, 'W', 20, helppos);
        helppos.y=224;
        TextOnScreen(screen, "v pour jouer vert", FONT_PATH, 'W', 20, helppos);
        helppos.y=244;
        TextOnScreen(screen, "q pour quitter la partie", FONT_PATH, 'W', 20, helppos);
        helppos.y=284;
        TextOnScreen(screen, "Pressez h pour", FONT_PATH, 'W', 25, helppos);
        helppos.y=304;
        TextOnScreen(screen, "ouvrir l'aide en jeu", FONT_PATH, 'W', 25, helppos);
        helppos.y=344;
        TextOnScreen(screen, "Pressez r pour", FONT_PATH, 'W', 25, helppos);
        helppos.y=364;
        TextOnScreen(screen, "revenir a la partie", FONT_PATH, 'W', 25, helppos);


        SDL_WaitEvent(&BackToGame);
    }
    BlackScreen(screen);

    return 0;
}


char HomePage(SDL_Surface *screen){

    BlackScreen(screen);
    int gamestate=0;

    SDL_Event move;
    int actualpos=0;
    SDL_Surface *menuimg=IMG_Load(IMG_PATH);

    SDL_Rect menupos;
    menupos.x=screen->w*LOGOPOSW - 250/2;
    menupos.y=screen->h*LOGOPOSH - 215/2;
    SDL_BlitSurface(menuimg, NULL, screen, &menupos);

    menupos.x=screen->w*TITLEPOS;
    menupos.y=screen->h/10;
    TextOnScreen(screen, "Colorflood", FONT_PATH, 'W', 40, menupos);


    menupos.y=screen->h*MENUPOS;
    menupos.x=screen->w*STARTPOS;


    TextOnScreen(screen, "Start", FONT_PATH, 'G', 20, menupos);

    menupos.x=screen->w*CONTROLSPOS;
    TextOnScreen(screen, "Controles", FONT_PATH, 'W', 20, menupos);

    menupos.x=screen->w*QUITPOS;
    TextOnScreen(screen, "Quitter", FONT_PATH, 'W', 20, menupos);
    /*
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

                          TextOnScreen(screen, "Start", FONT_PATH, 'W', 20, menupos);

                          menupos.x=screen->w*CONTROLSPOS;
                          TextOnScreen(screen, "Controles", FONT_PATH, 'W', 20, menupos);

                          menupos.x=screen->w*QUITPOS;
                          TextOnScreen(screen, "Quitter", FONT_PATH, 'G', 20, menupos);
                          actualpos = 2;
                          break;
                      }
                      else if (actualpos == 1) {
                          menupos.x=screen->w*STARTPOS;

                          TextOnScreen(screen, "Start", FONT_PATH, 'G', 20, menupos);

                          menupos.x=screen->w*CONTROLSPOS;
                          TextOnScreen(screen, "Controles", FONT_PATH, 'W', 20, menupos);

                          menupos.x=screen->w*QUITPOS;
                          TextOnScreen(screen, "Quitter", FONT_PATH, 'W', 20, menupos);
                          actualpos = 0;
                          break;
                      }
                      else if (actualpos == 2) {
                          menupos.x=screen->w*STARTPOS;

                          TextOnScreen(screen, "Start", FONT_PATH, 'W', 20, menupos);

                          menupos.x=screen->w*CONTROLSPOS;
                          TextOnScreen(screen, "Controles", FONT_PATH, 'G', 20, menupos);

                          menupos.x=screen->w*QUITPOS;
                          TextOnScreen(screen, "Quitter", FONT_PATH, 'W', 20, menupos);
                          actualpos = 1;
                          break;
                      }

                  case SDLK_RIGHT :
                      if (actualpos == 0) {
                          menupos.x=screen->w*STARTPOS;

                          TextOnScreen(screen, "Start", FONT_PATH, 'W', 20, menupos);

                          menupos.x=screen->w*CONTROLSPOS;
                          TextOnScreen(screen, "Controles", FONT_PATH, 'G', 20, menupos);

                          menupos.x=screen->w*QUITPOS;
                          TextOnScreen(screen, "Quitter", FONT_PATH, 'W', 20,menupos);
                          actualpos = 1;
                          break;
                      }
                      else if (actualpos == 1) {
                          menupos.x=screen->w*STARTPOS;

                          TextOnScreen(screen, "Start", FONT_PATH, 'W', 20,menupos);

                          menupos.x=screen->w*CONTROLSPOS;
                          TextOnScreen(screen, "Controles", FONT_PATH, 'W', 20, menupos);

                          menupos.x=screen->w*QUITPOS;
                          TextOnScreen(screen, "Quitter", FONT_PATH, 'G', 20,menupos);
                          actualpos = 2;
                          break;
                      }
                      else if (actualpos == 2) {
                          menupos.x=screen->w*STARTPOS;

                          TextOnScreen(screen, "Start", FONT_PATH, 'G', 20,menupos);

                          menupos.x=screen->w*CONTROLSPOS;
                          TextOnScreen(screen, "Controles", FONT_PATH, 'W', 20, menupos);

                          menupos.x=screen->w*QUITPOS;
                          TextOnScreen(screen, "Quitter", FONT_PATH, 'W', 20,menupos);
                          actualpos = 0;
                          break;
                      }

                  case SDLK_RETURN :
                      if (actualpos == 0) {
                          exitcond=1;
                          gamestate=1;
                          break;
                      }
                      else if (actualpos == 1) {
                          gamestate=2;
                          exitcond=1;
                          break;

                      }
                      else if (actualpos == 2) {
                          gamestate=5;
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
    return gamestate;
}



int GameLoop(SDL_Surface *screen, int n, char color, int kmax, char **colortable, int **connexetab, SDL_Surface *colorcase) {

    BlackScreen(screen);
    SDL_Event keyevent;

    /*-----Params de placement-----*/
    int off = screen->h*OFF;
    int boardS = screen->h - 2*off; /*taille d'un coté du board*/
    int squareS = boardS/n; /*taille du côté d'un carré*/

    int gamestate;

    int k=0;
    char msgCount[64];
    SDL_Rect txtpos;
    txtpos.y=screen->h*SCOREPOSH;
    txtpos.x=screen->w*SCOREPOSW;

    while(!wintest(connexetab, n) && color!='Q' && kmax>=k) {
        updateCaseColor(colortable, colorcase, screen, n, off, boardS, squareS);

        if (k%10==1) {
            sprintf(msgCount, "Nombre de coups :  %d/%d ",k, kmax);
        }
        else {
            sprintf(msgCount, "Nombre de coups : %d/%d ", k, kmax);
        }

        TextOnScreen(screen, msgCount,FONT_PATH, color, 20,txtpos);
        SDL_WaitEvent(&keyevent);

        /*
         * Mettre l'event j'appuie sur une touche dans un fonction
         */

        switch (keyevent.type){
            case SDL_KEYDOWN :
                /*
                 * Premier switch : On appuie sur une touche ou pas
                 */
                switch(keyevent.key.keysym.sym) {
                    /*
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
                        HelpPage(screen);
                        break;
                    case SDLK_q:
                        color='Q';
                    default :
                        break;
                }
            default :
                break;

        }
        updateconnexetab(colortable, connexetab, color, n);
        switchconnexecolors(colortable, connexetab, color, n);


    }
    if (kmax<k){
        gamestate=4;
    }

    if (kmax>=k){
        gamestate=3;
    }
    if (color=='Q'){
        gamestate=5;
    }
    return gamestate;
}
/**
 * @param screen Ecran
 * @return Renvoie le gamestate
 **/

int LooseScreen(SDL_Surface *screen){
    SDL_Rect pos;

    BlackScreen(screen);

    SDL_Event event;
    srand(time(NULL));

    int gamestate=0;
    char color[6]={'R','B','V','G','M','J'};
    while(gamestate==0){
        pos.x=screen->w*TITLEPOS;
        pos.y=screen->h/10;
        TextOnScreen(screen, "Defaite !", FONT_PATH, color[rand()%6], 40,pos);
        pos.y=screen->h/2;
        TextOnScreen(screen, "r pour rejouer", FONT_PATH, 'V', 40,pos);
        pos.y=3*screen->h/4;
        TextOnScreen(screen, "q pour quitter", FONT_PATH, 'R', 40,pos);
        SDL_WaitEvent(&event);
        switch(event.type) {
            case SDL_KEYDOWN :
                switch (event.key.keysym.sym) {
                    case SDLK_q :
                        gamestate=5;
                        break;
                    case SDLK_r:
                        gamestate=6;
                        break;
                    default :
                        break;

                }
            default:
                break;
        }

    }
    return gamestate;
}

/**
 * @param screen Ecran
 * @return Renvoie le gamestate
 **/
int VictoryScreen(SDL_Surface *screen){
    SDL_Rect pos;

    BlackScreen(screen);

    SDL_Event event;
    srand(time(NULL));

    int gamestate=0;
    char color[6]={'R','B','V','G','M','J'};
    while(gamestate==0){
      pos.x=screen->w*TITLEPOS;
      pos.y=screen->h/10;
      TextOnScreen(screen, "Victoire !", FONT_PATH, color[rand()%6], 40,pos);
      pos.y=screen->h/2;
      TextOnScreen(screen, "r pour rejouer", FONT_PATH, 'V', 40,pos);
      pos.y=3*screen->h/4;
      TextOnScreen(screen, "q pour quitter", FONT_PATH, 'R', 40,pos);
        SDL_WaitEvent(&event);
        switch(event.type) {
            case SDL_KEYDOWN :
                switch (event.key.keysym.sym) {
                    case SDLK_q :
                        gamestate=5;
                        break;
                    case SDLK_r:
                        gamestate=6;
                        break;
                    default :
                        break;

                }
            default:
                break;
        }

    }
    return gamestate;
}



/* RGB Color Code :
 * "R" (255,0,0)
 * "V" (0,204,0)
 * "G" (128,128,128)
 * "B" (0,0,255)
 * "M" (102,51,0)
 * "J" (255,255,0)
 * */
