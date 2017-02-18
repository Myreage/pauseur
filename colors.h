#ifndef COLORS_H
#define COLORS_H

int wintest(int **connexetab, int n);
int isconnexe(char **connexetable, int x, int y, int n);
void updateconnexetab(char **colortable, char **connexetab, char color, int n);
void switchconnexecolors(char **colortable, char **connexetab, char color, int n);
#endif
