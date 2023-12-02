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

void prepend(struct Node *head,int val) {
    struct Node* temp = malloc(sizeof(struct Node));
    temp->val=val;
    temp->next=NULL;
    if(head!=NULL)
        temp->next = head->next;       
    (*head).next=temp;

}

void append(struct Node *head,int val) {
    struct Node* temp =malloc(sizeof(struct Node));
    temp->val=val;
    temp->next=NULL;
    struct Node* curr = head;
    while(curr->next!=NULL) curr=curr->next;
    (*curr).next=temp;
}

int first(struct Node *head) {
    if(isEmpty(head)) return -1;
    struct Node *temp = head->next;
    int val = temp->val;
    head->next =head->next->next;
    return val;
}

int isEmpty(struct Node*head) {
    return head->next==NULL;
}