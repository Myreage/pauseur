#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include "datastruct.h"
#include "colors.h"

int main(){
    int n=6;
    char **colortable=createcolortable(n);

    fillcolortablerand(colortable, n);
    displaycolortable(colortable, n);
    switchcolor(colortable, 'R', 0, 0);
    displaycolortable(colortable, n);
    fillcolortablefile(colortable, n, "./colortablefile.txt");
    displaycolortable(colortable, n);
    createnewcolorfile("bite.txt", n);
    /*freecolortable(colortable, n);*/
    return 0;
}