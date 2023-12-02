struct Node {
    int val;
    struct Node* next;
};

void traverse(struct Node*);
void prepend(struct Node*,int);
void append(struct Node*,int );