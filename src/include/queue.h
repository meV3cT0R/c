#include <node.h>

struct Queue {
    struct Node q;
};

void enqueue(struct Queue*,int);
int dequeue(struct Queue*);
int isEmptyQ(struct Queue*);
