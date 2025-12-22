#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *left, *right;
} Node;

Node* buildFromLevelArray(int arr[], int m, int idx) {
    if (idx >= m) return NULL;
    if (arr[idx] == -1) return NULL;
    Node* root = malloc(sizeof(Node));
    root->key = arr[idx];
    root->left = buildFromLevelArray(arr, m, 2*idx + 1);
    root->right = buildFromLevelArray(arr, m, 2*idx + 2);
    return root;
}

int max(int a,int b){return a>b?a:b;}

int height_and_fillBF(Node* root) {
    if (!root) return 0;
    int lh = height_and_fillBF(root->left);
    int rh = height_and_fillBF(root->right);
    int bf = lh - rh;
    return 1 + max(lh, rh);
}

int computeHeight(Node* root) {
    if (!root) return 0;
    int lh = computeHeight(root->left);
    int rh = computeHeight(root->right);
    return 1 + (lh > rh ? lh : rh);
}

int isBalancedAndPrintBF(Node* root) {
    if (!root) { printf("Tree is empty\n"); return 1; }

    int balanced = 1;

    int check(Node* r) {
        if (!r) return 0;
        int lh = check(r->left);
        int rh = check(r->right);
        int bf = lh - rh;
        if (bf > 1 || bf < -1) balanced = 0;
        return 1 + (lh > rh ? lh : rh);
    }
    check(root);


    printf("Node : BalanceFactor (level-order)\n");

    typedef struct Q { Node* n; struct Q* next; } Q;
    Q *front=NULL, *rear=NULL;
    void qpush(Node* nd){ Q* q=malloc(sizeof(Q)); q->n=nd; q->next=NULL; if(!rear) front=rear=q; else {rear->next=q; rear=q;} }
    Node* qpop(){ if(!front) return NULL; Q* t=front; Node* r=t->n; front=front->next; if(!front) rear=NULL; free(t); return r;}
    qpush(root);
    while (front) {
        Node* cur = qpop();
        int lh = computeHeight(cur->left);
        int rh = computeHeight(cur->right);
        printf("%d : %d\n", cur->key, lh - rh);
        if (cur->left) qpush(cur->left);
        if (cur->right) qpush(cur->right);
    }

    if (balanced) printf("The tree IS height-balanced (AVL property).\n");
    else printf("The tree is NOT height-balanced.\n");
    return balanced;
}

int main() {
    int m;
    printf("Enter number of positions in level-order array (include -1 for nulls): ");
    if (scanf("%d",&m)!=1 || m<=0) return 0;
    int *arr = malloc(sizeof(int)*m);
    printf("Enter %d integers (-1 for null):\n", m);
    for (int i=0;i<m;i++) scanf("%d",&arr[i]);
    Node* root = buildFromLevelArray(arr, m, 0);
    isBalancedAndPrintBF(root);
    free(arr);
    return 0;
}
/*

Enter number of positions in level-order array (include -1 for nulls): 4
Enter 4 integers (-1 for null):
2
4
8
5
Node : BalanceFactor (level-order)
2 : 1
4 : 1
8 : 0
5 : 0
The tree IS height-balanced (AVL property).

*/