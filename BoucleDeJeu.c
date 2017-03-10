void GameLoop(SDL_Surface *screen, int n, char color, int kmax, char **colortable, int **connexetab, SDL_Surface *colorcase)
{
  SDL_Event keyevent;

  int k=0;
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
                  case SDLK_ESCAPE :
                      HomePage(screen,n,color);
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
}
