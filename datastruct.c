#include <stdlib.h>
#include <stdio.h>
#include <time.h>

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
    srand(time(NULL));
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


int isconnexe(char **connexetable, int x, int y, int n){
    int res;
    if (connexetable[x][y]) res=1;
    else if (x+1<n && connexetable[x+1][y]==1) res=1;
    else if (x-1>0 && connexetable[x-1][y]==1) res=1;
    else if (y+1<n && connexetable[x][y+1]==1) res=1;
    else if (y-1>0 && connexetable[x][y-1]==1) res=1;
    else res=0;
    return res;
}
void updateconnexetab(char **colortable, char **connexetab, char color, int n){
    /* Je pense que la fonction est à modifier dans le cas ou il y a un groupe de couleurs connexes ou peut être regler le problème
     * avec un while style tant que (connexetable!=updateconnexetab(...)) (En changeant le type de la fonction) */
    int i,j;
    for (i=0; i<n;i++){
        for (j=0; j<n; j++){
            if (isconnexe(connexetab, i, j, n) && colortable[i][j]==color) connexetab[i][j]=1;
        }
    }
}

void switchconnexecolors(char **colortable, char **connexetable, char color, int n){
    updateconnexetab(colortable, connexetable, color, n);
    int i,j;
    for (i=0; i<n;i++){
        for (j=0; j<n; j++){
            if (connexetable[i][j]==1) switchcolor(colortable, color, i, j);
        }
    }
}

int main(){
    int n=12;
    char **colortable=createcolortable(n);
    fillcolortablerand(colortable, n);
    displaycolortable(colortable, n);
    switchcolor(colortable, 'R', 0, 0);
    displaycolortable(colortable, n);
    freecolortable(colortable, n);
}

