#include <stdlib.h>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include "datastruct.h"
#include "colors.h"


int getche(void) {
    /**
     * Permet de récuperer un caractère entré par l'utilisateur.
     */
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}

/*!\mainpage Colorflood : Les Pauseurs
 * \section intro_sec Mode d'Emploi :
 * Appuyez sur "R" "V" "G" "B" "M" "J" pour changer la couleur de la composante connexe à la première case.
 *
 * \section install_sec Compilation et Exécution :
 * Pour l'execution normale : make && ./Colorflood \n
 * Pour l'execution des tests : make testColors && make testDatastruct && ./TestColors && ./TestDatastruct \n
 * Pour l'execution avec affichage graphique : make gui && ./guiColorflood TailleGrille NombredeCoups \n
 * 	Pour le dimensionnement de la fenêtre, il est nécéssaire d'executer le script setup.sh avant execution du programme
	ou d'entrer manuellement la dimension de l'écran dans le fichier config.ini (largeurxhauteur de l'écran en pixels (Essentiellement pour les machines Windows))
 * @return
 */

int main(){
    int n=6;
    char **colortable=createcolortable(n);
    int **connexetab=createconnexetab(n);
    fillcolortablerand(colortable, n);
    char color=colortable[0][0];
    updateconnexetab(colortable, connexetab, color, n);
    displaycolortable(colortable, n);
    while (!wintest(connexetab, n)){
        displaycolortable(colortable, n);
        displayconnexetab(connexetab, n);
        color=getche();
        if (color=='B' || color=='V' || color=='R' || color=='J'|| color=='M'|| color=='G'){
            switchconnexecolors(colortable, connexetab, color, n);
        }
        else printf("Entrée invalide !\n Entrée autorisée : 'B','V','R','J','M','G' \n");
    }
    printf(" Victoire !\n");
    freecolortable(colortable, n);
    freeconnextab(connexetab, n);
    return 0;
}
