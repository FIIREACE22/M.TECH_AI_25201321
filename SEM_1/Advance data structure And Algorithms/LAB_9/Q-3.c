#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* createNode(int data) {
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    return newnode;
}

Node* insert(Node* root, int data) {
    if (root == NULL)
        return createNode(data);

    int choice;
    printf("Insert %d to left(1) or right(2) of %d? ", data, root->data);
    scanf("%d", &choice);

    if (choice == 1)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}


int isBSTUtil(Node* root, int min, int max) {
    if (root == NULL)
        return 1;

    if (root->data <= min || root->data >= max)
        return 0;

    return isBSTUtil(root->left, min, root->data) &&
           isBSTUtil(root->right, root->data, max);
}

int isBST(Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

int main() {
    Node* root = NULL;
    int n, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Tree is empty.\n");
        return 0;
    }

    printf("\nEnter root value: ");
    scanf("%d", &value);
    root = createNode(value);

    for (int i = 1; i < n; i++) {
        printf("Enter next node value: ");
        scanf("%d", &value);
        insert(root, value);
    }

    if (isBST(root))
        printf("\nThe given binary tree IS a BST.\n");
    else
        printf("\nThe given binary tree is NOT a BST.\n");

    return 0;
}
/*

Enter number of nodes: 3

Enter root value: 9
Enter next node value: 6
Insert 6 to left(1) or right(2) of 9? 1
Enter next node value: 5
Insert 5 to left(1) or right(2) of 9? 1
Insert 5 to left(1) or right(2) of 6? 2

The given binary tree is NOT a BST.

*/