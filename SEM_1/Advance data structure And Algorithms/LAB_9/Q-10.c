#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key, height;
    struct Node *left, *right;
} Node;

Node* newNode(int k){ Node* p=malloc(sizeof(Node)); p->key=k; p->height=1; p->left=p->right=NULL; return p; }
int height(Node* n){ return n ? n->height : 0; }
int max(int a,int b){ return a>b?a:b; }
int bf(Node* n){ return n ? height(n->left) - height(n->right) : 0; }

Node* rightRotate(Node* y) {
    Node* x = y->left; Node* T2 = x->right;
    x->right = y; y->left = T2;
    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));
    return x;
}
Node* leftRotate(Node* x) {
    Node* y = x->right; Node* T2 = y->left;
    y->left = x; x->right = T2;
    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));
    return y;
}

Node* minValueNode(Node* node) {
    Node* cur = node;
    while (cur->left) cur = cur->left;
    return cur;
}

Node* insertAVL(Node* node, int key); 

Node* deleteAVL(Node* root, int key) {
    if (!root) return root;
    if (key < root->key) root->left = deleteAVL(root->left, key);
    else if (key > root->key) root->right = deleteAVL(root->right, key);
    else {
        
        if (!root->left || !root->right) {
            Node* temp = root->left ? root->left : root->right;
            if (!temp) { 
                temp = root;
                root = NULL;
            } else { 
                *root = *temp;
            }
            free(temp);
        } else {
            Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteAVL(root->right, temp->key);
        }
    }
    if (!root) return root;

    root->height = 1 + max(height(root->left), height(root->right));
    int balance = bf(root);

   
    if (balance > 1 && bf(root->left) >= 0) {
        printf("Rotation during deletion at node %d: Right Rotation (LL case)\n", root->key);
        return rightRotate(root);
    }
   
    if (balance > 1 && bf(root->left) < 0) {
        printf("Rotation during deletion at node %d: Left-Right Rotation (LR case)\n", root->key);
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
 
    if (balance < -1 && bf(root->right) <= 0) {
        printf("Rotation during deletion at node %d: Left Rotation (RR case)\n", root->key);
        return leftRotate(root);
    }
   
    if (balance < -1 && bf(root->right) > 0) {
        printf("Rotation during deletion at node %d: Right-Left Rotation (RL case)\n", root->key);
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    printf("Rotation during deletion of %d: None at node %d\n", key, root->key);
    return root;
}

void inorder(Node* r) { if(!r) return; inorder(r->left); printf("%d ", r->key); inorder(r->right); }

int main() {
    int n;
    printf("Enter number of initial nodes to insert: ");
    if (scanf("%d",&n)!=1 || n<0) return 0;
    Node* root = NULL;
    printf("Enter %d keys:\n", n);
    for (int i=0;i<n;i++){
        int x; scanf("%d",&x);
        root = insertAVL(root, x);
    }

    int d;
    printf("Enter number of deletions: ");
    scanf("%d",&d);
    printf("Enter %d keys to delete:\n", d);
    for (int i=0;i<d;i++){
        int key; scanf("%d",&key);
        root = deleteAVL(root, key);
        int h = height(root);
        printf("Height of tree after deletion: %d\n", h);
        printf("Inorder now: ");
        inorder(root);
        printf("\n---------------------\n");
    }
    return 0;
}

Node* insertAVL(Node* node, int key) {
    if (!node) return newNode(key);
    if (key < node->key) node->left = insertAVL(node->left, key);
    else if (key > node->key) node->right = insertAVL(node->right, key);
    else return node;
    node->height = 1 + max(height(node->left), height(node->right));
    int balance = bf(node);
    if (balance > 1 && key < node->left->key) {
        return rightRotate(node);
    }
    if (balance < -1 && key > node->right->key) {
        return leftRotate(node);
    }
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}
/*

Enter number of initial nodes to insert: 5
Enter 5 keys:
2
4
5
1
8
Enter number of deletions: 1
Enter 1 keys to delete:
8
Rotation during deletion of 8: None at node 5
Rotation during deletion of 8: None at node 4
Height of tree after deletion: 3
Inorder now: 1 2 4 5 
---------------------

*/
