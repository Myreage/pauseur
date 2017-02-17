#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include "datastruct.h"
#include "colors.h"

int **createconnexetab(int n){
    int i;
    int **tab=NULL;
    tab=malloc(n*sizeof(int *));
    for (i=0;i<n;i++) tab[i]=malloc(n*sizeof(int));
    return tab;
}

int getche(void) {
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

void displayconnexetab(int **tab, int n){
    int i,j;
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            printf("%d",tab[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(){
    int n=6;
    char **colortable=createcolortable(n);
    int **connexetab=createconnexetab(n);
    connexetab[0][0]=1;
    char color=colortable[0][0];
    fillcolortablerand(colortable, n);
    updateconnexetab(colortable, connexetab, color, n);
    displaycolortable(colortable, n);

    while (!wintest(connexetab, n)){
        displaycolortable(colortable, n);
        displayconnexetab(connexetab, n);
        printf("new color ?\n");
        color=getche();
        switchconnexecolors(colortable, connexetab, color, n);

    }
    return 0;
}