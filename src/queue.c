#include <queue.h>
void enqueue(struct Queue* queue,int x) {
    append(&(queue->q),x);
}

int dequeue(struct Queue* queue) {
    return first(&(queue->q));
}

int isEmptyQ(struct Queue* queue) {
    return isEmpty(&(queue->q));
}