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

Node* createNode(int data) {
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    return newnode;
}

void levelOrder(Node* root) {
    if (root == NULL) {
        printf("Tree is empty.\n");
        return;
    }

    Queue q;
    q.front = q.rear = -1;

    enqueue(&q, root);

    printf("Level Order Traversal: ");

    while (!isEmpty(&q)) {
        Node* current = dequeue(&q);
        printf("%d ", current->data);

        if (current->left)
            enqueue(&q, current->left);

        if (current->right)
            enqueue(&q, current->right);
    }
    printf("\n");
}

int main() {
    

    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);

    levelOrder(root);

    return 0;
}
/*

Level Order Traversal: 1 2 3 4 5 6 

*/