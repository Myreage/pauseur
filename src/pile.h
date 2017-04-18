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

/**
 * @return Une pile* initialisée
 */
pile *initpile();


/**
 * @param pile La pile à free
 */
void freepile(pile *pile);

/**
 * @param pile La pile sur laquelle empiler
 * @param value La valeur à empiler
 */
void stack(pile *file, char value);

/**
 * @param pile La pile à pop
 */
char pop(pile *pile);


void displayreversepile(pile * pile);
void displaypile(pile *pile);

#endif
