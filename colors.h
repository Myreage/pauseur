#ifndef COLORS_H
#define COLORS_H

int wintest(int **connexetab, int n);
int isconnexe(int **connexetable, int x, int y, int n);
void updateconnexetab(char **colortable, int **connexetab, char color, int n);
void switchconnexecolors(char **colortable, int **connexetab, char color, int n);
#endif
