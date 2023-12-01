struct Node {
    int val;
    struct Node* next;
};

void traverse(struct Node* node);
void prepend(struct Node **head,int val);