#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *left, *right;
} Node;

Node* newNode(int k) { Node* p = malloc(sizeof(Node)); p->key=k; p->left=p->right=NULL; return p; }

Node* buildBalanced(int arr[], int l, int r) {
    if (l>r) return NULL;
    int mid = (l + r) / 2;
    Node* root = newNode(arr[mid]);
    root->left = buildBalanced(arr, l, mid-1);
    root->right = buildBalanced(arr, mid+1, r);
    return root;
}

typedef struct QNode { Node* node; struct QNode* next; } QNode;
typedef struct Queue { QNode *front, *rear; } Queue;
void push(Queue *q, Node* n) {
    QNode* qn = malloc(sizeof(QNode)); qn->node=n; qn->next=NULL;
    if (!q->rear) q->front=q->rear=qn; else { q->rear->next=qn; q->rear=qn; }
}
Node* pop(Queue *q) {
    if (!q->front) return NULL;
    QNode* t = q->front; Node* n = t->node;
    q->front = t->next; if (!q->front) q->rear=NULL; free(t);
    return n;
}

void levelOrder(Node* root) {
    if (!root) { printf("(empty)\n"); return; }
    Queue q = {NULL, NULL};
    push(&q, root);
    while (q.front) {
        Node* cur = pop(&q);
        printf("%d ", cur->key);
        if (cur->left) push(&q, cur->left);
        if (cur->right) push(&q, cur->right);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter number of sorted elements: ");
    if (scanf("%d", &n)!=1 || n<=0) return 0;
    int *arr = malloc(sizeof(int)*n);
    printf("Enter %d sorted values:\n", n);
    for (int i=0;i<n;i++) scanf("%d",&arr[i]);
    Node* root = buildBalanced(arr, 0, n-1);
    printf("Level-order traversal of balanced BST:\n");
    levelOrder(root);
    free(arr);
    return 0;
}

/*
Enter number of sorted elements: 4
Enter 4 sorted values:
2
3
5
6
Level-order traversal of balanced BST:
3 2 5 6
*/
