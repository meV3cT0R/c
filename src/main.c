#include <stdio.h>
#include <tree.h>
#include <stdlib.h>
#include <mergeStrings.h>
#include <graph.h>
#include <queue.h>

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
    struct Graph graph;

    initGraph(&graph);
    insertEdge(&graph,1,2);
    insertEdge(&graph,1,7);
    insertEdge(&graph,1,8);
    insertEdge(&graph,2,3);
    insertEdge(&graph,2,5);
    insertEdge(&graph,2,5);
    insertEdge(&graph,3,5);
    insertEdge(&graph,3,4);
    insertEdge(&graph,5,6);
    insertEdge(&graph,5,4);

    printf("Breadth First search:");
    bfs(&graph,1);

    printf("Depth First Search: ");
    dfs(&graph,1);
    printf("\n");
    struct Queue queue;

    enqueue(&queue,2);

    printf("Queue:\n");
    int i=0;
    while(!isEmptyQ(&queue)){
        int d = dequeue(&queue);
        if(i++==0) enqueue(&queue,3);
        printf("%d ",d);
    }
    printf("\n");
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