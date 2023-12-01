#include <node.h>
#include <stdio.h>
#include <stdlib.h>
void traverse(struct Node* node) {
    struct Node* curr = node;

    while(curr!=NULL) {
        printf("%d ",curr->val);
        curr=curr->next;
    }
    printf("\n");
}

void prepend(struct Node **head,int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->val=val;
    temp->next=NULL;
    if(temp!=NULL) {
        if(head==NULL) {
            *head = temp;
        }else {
            temp->next = *head;
            *head=temp;
        }
    }
}