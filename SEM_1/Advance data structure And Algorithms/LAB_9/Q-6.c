#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node {
    int key;
    struct Node *left, *right;
} Node;

Node* newNode(int k) { Node* p = malloc(sizeof(Node)); p->key=k; p->left=p->right=NULL; return p; }
Node* insert(Node* r, int k) {
    if (!r) return newNode(k);
    if (k < r->key) r->left = insert(r->left, k);
    else if (k > r->key) r->right = insert(r->right, k);
    return r;
}

int kth_smallest_util(Node* root, int k, int *cnt) {
    if (!root) return INT_MIN;
    int left = kth_smallest_util(root->left, k, cnt);
    if (left != INT_MIN) return left;
    (*cnt)++;
    if (*cnt == k) return root->key;
    return kth_smallest_util(root->right, k, cnt);
}

int kth_largest_util(Node* root, int k, int *cnt) {
    if (!root) return INT_MIN;
    int right = kth_largest_util(root->right, k, cnt);
    if (right != INT_MIN) return right;
    (*cnt)++;
    if (*cnt == k) return root->key;
    return kth_largest_util(root->left, k, cnt);
}

int main() {
    int n;
    printf("Enter number of nodes: ");
    if (scanf("%d", &n)!=1 || n<=0) return 0;
    Node* root = NULL;
    printf("Enter %d values:\n", n);
    for (int i=0;i<n;i++){ int x; scanf("%d",&x); root = insert(root,x); }
    int k; printf("Enter k: "); scanf("%d",&k);
    int cnt=0;
    int ks = kth_smallest_util(root, k, &cnt);
    if (ks==INT_MIN) printf("%d-th smallest does not exist\n", k);
    else printf("%d-th smallest = %d\n", k, ks);
    cnt=0;
    int kl = kth_largest_util(root, k, &cnt);
    if (kl==INT_MIN) printf("%d-th largest does not exist\n", k);
    else printf("%d-th largest = %d\n", k, kl);
    return 0;
}

/*
Enter number of nodes: 4
Enter 4 values:
4
8
2
6
Enter k: 1
1-th smallest = 2
1-th largest = 8
*/
