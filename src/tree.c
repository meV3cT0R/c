#include <stdio.h>
#include <tree.h>
#include <node.h>
#include <stdlib.h>

struct Node* head;

struct TreeNode* talloc(int val) {
    struct TreeNode* temp = malloc(sizeof(struct TreeNode));
    temp->val=val;
    temp->left=temp->right=NULL;
    return temp;
}
void insert(struct TreeNode **root,int val) {
    if((*root)==NULL){ *root=talloc(val); return;}
    if((*root)->val < val) {
        if((*root)->left==NULL) (*root)->left=talloc(val);
        else insert(&((*root)->left),val);
    }else {
        if((*root)->right==NULL) (*root)->right=talloc(val);
        else insert(&((*root)->right),val);       
    }
}

void inOrderTraverse(struct TreeNode* root) {
    if(root==NULL) return;
    inOrderTraverse(root->left);
    printf("%d ",root->val);
    inOrderTraverse(root->right);
}
void inOrderSort(struct TreeNode* root) {
    if(!root) return;
    inOrderSort(root->left);
    struct Node* temp = malloc(sizeof(struct Node*));
    printf("%d ",root->val);
    temp->val= root->val;
    if(head) temp->next=head;
    head=temp;
    inOrderSort(root->right);
}

void printLinkedList() {
    printf("hello");
    if(head==NULL) return;
    struct Node* curr = head;

    while(curr!=NULL) {
        printf("%d ",curr->val);
        curr=curr->next;
    }
    printf("\n");
}