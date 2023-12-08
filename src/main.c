#include <stdio.h>
#include <tree.h>
#include <stdlib.h>
#include <mergeStrings.h>
#include <graph.h>
#include <queue.h>
#include <stdbool.h>
#include <string.h>
#include <removeDuplicates.h>
bool arrayStringsAreEqual(char** word1, int word1Size, char** word2, int word2Size) {
    int i=0,j=0,k=0,l=0;

    char a,b;
    while(i<word1Size && j<word2Size) {  
        while((a=*(word1[i]+k))!='\0' && (b=*(word2[j]+l))!='\0') {
            printf("a : %c b : %c \n",a,b);
            if(a!=b) return false;
            k++;
            l++;
        }
        if(a=='\0'){i++;k=0;}
        if(b=='\0'){j++;l=0;}
    }
    printf("a : %c \nb : %c \n",a,b);
    printf("len(a) : %d \nlen(b) : %d \n",strlen(word1[i])-k,strlen(word2[j])-l);
    printf("i : %d \nj : %d \n",i,j);
    return a=='\0' && b=='\0';
}
void rearrange(struct TreeNode **root) {
    if(*root==NULL) return;
    if((*root)->right!=NULL) rearrange(&((*root)->right));
    if((*root)->left==NULL) return;
    struct TreeNode* curr = (*root)->left;
    while(curr->right!=NULL) curr=curr->right;
    curr->right=*root;
    *root=(*root)->left;
    curr->right->left=NULL;
    rearrange(root);
}
struct ListNode* lalloc(int val) {
    struct ListNode* temp = malloc(sizeof(struct ListNode));
    temp->val = val;
    temp->next=NULL;
    return temp;
}
struct ListNode* reverse(struct ListNode* head) {
    struct ListNode* prev=NULL,*curr=head,*next;
    
    while(curr!=NULL) {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
void insertVal(struct ListNode *temp,int val) {
    struct ListNode *curr = temp;
    while(curr->next!=NULL) curr=curr->next;
    curr->next=lalloc(val);
}
void printList(struct ListNode *head) {
    while(head!=NULL) {
        printf("%d ",head->val);
        head=head->next;
    }
    printf("\n");
}
void reorderList(struct ListNode* head) {
    struct ListNode* slow=head,*fast=head,*temp=NULL;

    while(fast!=NULL && fast->next!=NULL) {
        temp=slow;
        slow=slow->next;
        fast=fast->next->next;
    }

    printf("temp->next->val: %d\n",temp->next->val);
    temp->next=NULL;
    printf("slow->val: %d\n",slow->val);
    printList(head);
    printList(slow);
    slow=reverse(slow);
    fast=head;


    struct ListNode* curr;
    while(fast!=NULL && fast->next!=NULL) {
        temp=slow;
        curr=slow->next;
        temp->next=fast->next;
        fast->next=temp;
        slow=curr;
        fast=temp->next;
        printf("slow->val: %d\n",slow->val);
    }
    printList(fast);
    printList(slow);

    fast->next=slow;
    
}
int main() {

    struct ListNode* head = lalloc(1);
    head->next = lalloc(2);
    insertVal(head,3);
    insertVal(head,4);
    insertVal(head,5);
    insertVal(head,6);
    insertVal(head,7);

    reorderList(head);


    while(head!=NULL){
        printf("%d ",head->val);
        head=head->next;
    }
    
    // struct Graph graph;

    // initGraph(&graph);
    // insertEdge(&graph,1,2,1);
    // insertEdge(&graph,1,7,1);
    // insertEdge(&graph,1,8,1);
    // insertEdge(&graph,2,3,1);
    // insertEdge(&graph,2,5,1);
    // insertEdge(&graph,2,5,1);
    // insertEdge(&graph,3,5,1);
    // insertEdge(&graph,3,4,1);
    // insertEdge(&graph,5,6,1);
    // insertEdge(&graph,5,4,1);

    // printf("Breadth First search:");
    // bfs(&graph,1);

    // printf("Depth First Search: ");
    // dfs(&graph,1);
    // printf("\n");

    // // printf("Prim's mst weight:%d\n",);
    // struct Queue queue;

    // enqueue(&queue,2);

    // printf("Queue:\n");
    // int i=0;
    // while(!isEmptyQ(&queue)){
    //     int d = dequeue(&queue);
    //     if(i++==0) enqueue(&queue,3);
    //     printf("%d ",d);
    // }
    // printf("\n");
    // // struct Node *head;

    // // prepend(&head,5);
    // // prepend(&head,3);
    // // traverse(head);


    // // struct TreeNode *root=NULL;
    // // insert(&root,1);
    // // insert(&root,2);
    // // inOrderTraverse(root);
    // // printf("\n");

    // struct TreeNode* root = malloc(sizeof(struct TreeNode*));
    // root->val = 2;
    // root->left = malloc(sizeof(struct TreeNode*));
    // root->left->val =1;
    // root->right = malloc(sizeof(struct TreeNode*));
    // root->right->val =3;
    // rearrange(&root);

    // while(root!=NULL) {
    //     printf("%d ",root->val);
    //     root= root->right;
    // }
    // printf("\n");

    // printf("%s\n",mergeAlternately("olleh","hello"));
    
    // struct Node head;

    // prepend(&head,1);
    // prepend(&head,2);
    // append(&head,3);
    // traverse(head.next);


    // char *word1[] = {"abc","d","defg"};
    // char *word2[] = {"abcddef"};

    // printf("Array Strings are Equal:%d \n",arrayStringsAreEqual(word1,2,word2,2));
printf("\n");
    return 0;
}