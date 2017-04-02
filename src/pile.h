#ifndef PILE_H
#define PILE_H

typedef struct f_Element f_Element;
struct f_Element{
    char value;
    struct f_Element *next;
};

typedef struct pile pile;
struct pile{
    int length;
    f_Element *first;
};

/* INIT/FREE */
pile *initpile();
void freepile(pile *pile);

/*Element manipulation*/
void stack(pile *file, char value);
char pop(pile *pile);
f_Element *getElement(pile *pile, int k);

/*DISPLAY*/
void displayreversepile(pile * pile);
void displaypile(pile *pile);

#endif
