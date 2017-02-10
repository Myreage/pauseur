#include <stdlib.h>
#include <stdio.h>
char **createcolortable(int n){
    int i;
    char **colortable=NULL;
    colortable=malloc(n*n*sizeof(char));
    for (i=0;i<n;i++) colortable[i]=malloc(n*sizeof(char));
    return colortable;
}

void freecolortable(char **colortable, int n){
    int i;
    for (i=0;i<n;i++){
        free(colortable[i]);
    }
    free(colortable);
}

void fillcolortablerand(char **colortable, int n){
    int i,j;
    char colors[6]={'B','V','R','J','M','G'};
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            colortable[i][j]=colors[rand()%6];
        }
    }
}

void fillcolortablefile(char **colortable, int n, char *filename){
    FILE *file=fopen(filename, "r");
    int i,j;
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            fscanf(file, "%c", &colortable[i][j]);
        }
    }
    fclose(file);
}

int wintest(char **colortable, int n){
    char color=colortable[0][0];
    int i,j;
    int res;
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            if (colortable[i][j]==color) res++;
        }
    }
    return(res==n*n);

}

void switchcolor(char **colortable, char color, int x, int y) {
    if (colortable[x][y] == ' ') printf("Error switch color\n");
    else colortable[x][y] = color;
}

void displaycolortable(char **colortable, int n){
    int i,j;
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            printf("%c",colortable[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

/*void updateconnexetab(char **colortable,char **connexetab, int n){*/ /* Je verrai bien un petit truc recursif }*/

/*void switchconnexecolors(char **colortable, char color, int x, int y){
    char initcolor=colortable[0][0];
}*/

int main(){
    int n=12;
    char **colortable=createcolortable(n);
    fillcolortablerand(colortable, n);
    displaycolortable(colortable, n);
    switchcolor(colortable, 'V', 0, 0);
    displaycolortable(colortable, n);
}

