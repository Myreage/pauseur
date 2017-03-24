

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


void thread(fifo *file, int value);
char popfirst(fifo *pile);
void freefifo(fifo *pile);
void displayfifo(fifo *pile);
