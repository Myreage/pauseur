#ifndef DATASTRUCT_H
#define DATASTRUCT_H


char** createcolortable(int n);
int **createconnexetab(int n);
void freecolortable(char **colortable, int n);
void freeconnextab(int **connextab, int n);
void fillcolortablerand(char **colortable, int n);
void fillcolortablefile(char **colortable, int n, char *filename);
void createnewcolorfile(char *name, int n);
void switchcolor(char **colortable, char color, int x, int y);
void displaycolortable(char **colortable, int n);
void displayconnexetab(int **connexetab, int n);


#endif