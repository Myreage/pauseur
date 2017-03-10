//
// Created by baron on 3/9/17.
//

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

#ifndef PAUSEUR_GUI_H
#define PAUSEUR_GUI_H

void SDLwait();
SDL_Surface *initscreen();
void updateCaseColor(char **colortable, SDL_Surface *colorcase, SDL_Surface *screen, int n,int off, int boardS, int squareS);
void TextOnScreen(SDL_Surface *screen, char *msg, char *font, char color, int fontsize, SDL_Rect pos);
void HelpPage(SDL_Surface *screen,int n);
void BlackScreen(SDL_Surface *screen);

#endif //PAUSEUR_GUI_H
