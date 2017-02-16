#ifndef DATASTRUCT_H
#define DATASTRUCT_H

char **createcolortable(int n);
void freecolortable(char **colortable, int n);;
void fillcolortablerand(char **colortable, int n);
int testfile (char *filename, int n);
void fillcolortablefile(char **colortable, int n, char *filename);
void createnewcolorfile(char *name, int n);
void switchcolor(char **colortable, char color, int x, int y);
void displaycolortable(char **colortable, int n);


#endif
