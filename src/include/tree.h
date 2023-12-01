struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

void insert(struct TreeNode**,int);
void inOrderTraverse(struct TreeNode*);
void inOrderSort(struct TreeNode*);
void printLinkedList();