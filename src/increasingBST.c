#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};


void rearrange(struct TreeNode* root) {
    if(root==NULL) return;
    if(root->right!=NULL) rearrange(root->right);
    if(root->left==NULL) return;
    struct TreeNode* curr = root->left;
    while(curr->right!=NULL) curr=curr->right;
    curr->right=root;
    root=root->left;
    curr->right->left=NULL;
    rearrange(root);
}
void main() {
    struct TreeNode* root = malloc(sizeof(struct TreeNode*));
    root->val = 2;
    root->left = malloc(sizeof(struct TreeNode*));
    root->left->val =1;
    root->right = malloc(sizeof(struct TreeNode*));
    root->right->val =3;
    rearrange(root);

    printf("%d ",root->left);
    while(root!=NULL) {
        printf("%d ",root->val);
        root= root->right;
    }
    printf("\n");
}