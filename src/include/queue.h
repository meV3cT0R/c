#include <node.h>

struct Queue {
    int val;
    struct Node *next;
};

void enqueue(struct Queue*,int);
int dequeue(struct Queue*);
int isEmptyQ(struct Queue*);