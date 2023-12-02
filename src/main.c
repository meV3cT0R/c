#include <stdio.h>
#include <tree.h>
#include <node.h>
#include <stdlib.h>
#include <mergeStrings.h>

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
int main() {
    // struct Node *head;

    // prepend(&head,5);
    // prepend(&head,3);
    // traverse(head);


    // struct TreeNode *root=NULL;
    // insert(&root,1);
    // insert(&root,2);
    // inOrderTraverse(root);
    // printf("\n");

    struct TreeNode* root = malloc(sizeof(struct TreeNode*));
    root->val = 2;
    root->left = malloc(sizeof(struct TreeNode*));
    root->left->val =1;
    root->right = malloc(sizeof(struct TreeNode*));
    root->right->val =3;
    rearrange(&root);

    while(root!=NULL) {
        printf("%d ",root->val);
        root= root->right;
    }
    printf("\n");

    printf("%s\n",mergeAlternately("olleh","hello"));
    
    struct Node head;

    prepend(&head,1);
    prepend(&head,2);
    append(&head,3);
    traverse(head.next);
    return 0;
}