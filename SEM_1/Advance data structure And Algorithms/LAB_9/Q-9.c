#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int key, height;
    struct Node *left, *right;
} Node;

Node* newNode(int k){ Node* p=malloc(sizeof(Node)); p->key=k; p->height=1; p->left=p->right=NULL; return p; }
int height(Node* n){ return n ? n->height : 0; }
int max(int a,int b){ return a>b?a:b; }
int bf(Node* n){ return n ? height(n->left) - height(n->right) : 0; }

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));
    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));
    return y;
}

Node* insertAVL(Node* node, int key) {
    if (!node) return newNode(key);
    if (key < node->key) node->left = insertAVL(node->left, key);
    else if (key > node->key) node->right = insertAVL(node->right, key);
    else return node; 

    node->height = 1 + max(height(node->left), height(node->right));
    int balance = bf(node);

    if (balance > 1 && key < node->left->key) {
        printf("Rotation performed: Right Rotation (LL case) at node %d\n", node->key);
        return rightRotate(node);
    }
 
    if (balance < -1 && key > node->right->key) {
        printf("Rotation performed: Left Rotation (RR case) at node %d\n", node->key);
        return leftRotate(node);
    }

    if (balance > 1 && key > node->left->key) {
        printf("Rotation performed: Left-Right Rotation (LR case) at node %d\n", node->key);
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key) {
        printf("Rotation performed: Right-Left Rotation (RL case) at node %d\n", node->key);
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    printf("Rotation performed: None at insertion of %d\n", key);
    return node;
}

void inorder_printBF(Node* root) {
    if (!root) return;
    inorder_printBF(root->left);
    printf("%d(bf=%d) ", root->key, bf(root));
    inorder_printBF(root->right);
}

int main() {
    int n;
    printf("Enter number of insertions: ");
    if (scanf("%d",&n)!=1 || n<=0) return 0;
    Node* root = NULL;
    printf("Enter %d keys to insert:\n", n);
    for (int i=0;i<n;i++){
        int x; scanf("%d",&x);
        root = insertAVL(root, x);
        printf("Inorder with balance factors after insertion %d: \n", x);
        inorder_printBF(root);
        printf("\n---------------------\n");
    }
    return 0;
}
/*

Enter number of insertions: 3
Enter 3 keys to insert:
1
Inorder with balance factors after insertion 1: 
1(bf=0) 
---------------------
5
Rotation performed: None at insertion of 5
Inorder with balance factors after insertion 5: 
1(bf=-1) 5(bf=0) 
---------------------
9
Rotation performed: None at insertion of 9
Rotation performed: Left Rotation (RR case) at node 1
Inorder with balance factors after insertion 9: 
1(bf=0) 5(bf=0) 9(bf=0) 
---------------------


*/