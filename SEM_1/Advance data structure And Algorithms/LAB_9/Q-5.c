
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *left, *right;
} Node;

Node* newNode(int key) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->key = key; p->left = p->right = NULL;
    return p;
}

Node* insert(Node* root, int key) {
    if (!root) return newNode(key);
    if (key < root->key) root->left = insert(root->left, key);
    else if (key > root->key) root->right = insert(root->right, key);
   
    return root;
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
}

int main() {
    int n;
    printf("Enter number of nodes: ");
    if (scanf("%d", &n)!=1 || n<=0) return 0;
    Node* root = NULL;
    printf("Enter %d values:\n", n);
    for (int i = 0; i < n; ++i) {
        int x; scanf("%d", &x);
        root = insert(root, x);
    }
    printf("Inorder traversal:\n");
    inorder(root);
    printf("\n");
    return 0;
}

/*
Enter number of nodes: 4   
Enter 4 values:
2
6
5
8
Inorder traversal:
2 5 6 8*/
