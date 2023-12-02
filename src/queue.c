#include <queue.h>
#include <stdlib.h>

void enqueue(struct Queue* queue,int x) {
    struct Node* temp =malloc(sizeof(struct Node));
    temp->val=x;
    temp->next=NULL;
    struct Node* curr = queue;
    while(curr->next!=NULL) curr=curr->next;
    (*curr).next=temp;
}

int dequeue(struct Queue* queue) {
    if(isEmptyQ(queue)) return -1;
    struct Node *temp = queue->next;
    int val = temp->val;
    queue->next =queue->next->next;
    return val;
}

int isEmptyQ(struct Queue* queue) {
    return queue->next==NULL;
}