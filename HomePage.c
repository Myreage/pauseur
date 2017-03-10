char HomePage(SDL_surface *screen, int n)
{
  BlackScreen(screen);
  SDL_Surface *menuimg=IMG_Load("drowncube.jpg");

  SDL_Event move;

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
}
