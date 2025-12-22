#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;


typedef struct Queue {
    Node* arr[100];
    int front, rear;
} Queue;

void enqueue(Queue *q, Node* node) {
    q->arr[++q->rear] = node;
}

Node* dequeue(Queue *q) {
    return q->arr[++q->front];
}

int isEmpty(Queue *q) {
    return q->front == q->rear;
}

Node* createNode(int value) {
    Node* newnode = (Node*) malloc(sizeof(Node));
    newnode->data = value;
    newnode->left = newnode->right = NULL;
    return newnode;
}


Node* buildTree() {
    int rootVal;
    printf("Enter root value (-1 for no node): ");
    scanf("%d", &rootVal);

    if (rootVal == -1)
        return NULL;

    Node* root = createNode(rootVal);

    Queue q;
    q.front = q.rear = -1;
    enqueue(&q, root);

    while (!isEmpty(&q)) {
        Node* current = dequeue(&q);
        int leftVal, rightVal;

        printf("Enter left child of %d (-1 for no node): ", current->data);
        scanf("%d", &leftVal);
        if (leftVal != -1) {
            current->left = createNode(leftVal);
            enqueue(&q, current->left);
        }

        printf("Enter right child of %d (-1 for no node): ", current->data);
        scanf("%d", &rightVal);
        if (rightVal != -1) {
            current->right = createNode(rightVal);
            enqueue(&q, current->right);
        }
    }
    return root;
}


void preorder(Node* root) {
    if (root) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(Node* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    printf("\n--- Build Binary Tree (Level Order) ---\n");
    Node* root = buildTree();

    printf("\nPreorder Traversal : ");
    preorder(root);

    printf("\nInorder Traversal  : ");
    inorder(root);

    printf("\nPostorder Traversal: ");
    postorder(root);

    printf("\n");
    return 0;
}

/*


--- Build Binary Tree (Level Order) ---
Enter root value (-1 for no node): 5
Enter left child of 5 (-1 for no node): 4
Enter right child of 5 (-1 for no node): 2
Enter left child of 4 (-1 for no node): -1
Enter right child of 4 (-1 for no node): -1
Enter left child of 2 (-1 for no node): -1
Enter right child of 2 (-1 for no node): -1

Preorder Traversal : 5 4 2 
Inorder Traversal  : 4 5 2 
Postorder Traversal: 4 2 5 

*/
