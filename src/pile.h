#ifndef PILE_H
#define PILE_H

typedef struct f_Element f_Element;
struct f_Element{
    char value;
    struct f_Element *next;
};

typedef struct fifo fifo;
struct fifo{
    int length;
    f_Element *first;
};

fifo *copyfifo(fifo *pile, int maxlenght);
fifo *initpile();
void thread(fifo *file, char value);
char popfirst(fifo *pile);
void freefifo(fifo *pile);
void displayfifo(fifo *pile);
fifo *copyfifo(fifo *pile, int maxlenght);
char *getElement(fifo *pile, int k);

#endif
