#include <stdio.h>
#include <stdlib.h>

/*        1
         / \
        2   3
       / \   \
      4   5   6        */
typedef struct Node { int val; struct Node *left, *right; } Node;

Node *newNode(int v, Node *l, Node *r) {
    Node *n = malloc(sizeof(Node));
    n->val = v; n->left = l; n->right = r;
    return n;
}

/* ---------- DFS: go deep first (recursion = the system stack) ---------- */
void preorder(Node *n)  { if (!n) return; printf("%d ", n->val); preorder(n->left); preorder(n->right); }
void inorder(Node *n)   { if (!n) return; inorder(n->left); printf("%d ", n->val); inorder(n->right); }
void postorder(Node *n) { if (!n) return; postorder(n->left); postorder(n->right); printf("%d ", n->val); }

/* ---------- BFS: level by level (uses a QUEUE) ---------- */
void bfs(Node *root) {
    Node *queue[50]; int front = 0, rear = 0;
    queue[rear++] = root;
    while (front < rear) {
        Node *n = queue[front++];                 /* dequeue */
        printf("%d ", n->val);
        if (n->left)  queue[rear++] = n->left;    /* enqueue children */
        if (n->right) queue[rear++] = n->right;
    }
}

/* ---------- Backtracking (DFS on a decision tree): subset sum ---------- */
int A[] = {3, 4, 5, 6}, N = 4, TARGET = 9;
void subset(int i, int sum, int path[], int len) {
    if (sum == TARGET) {                          /* solution found */
        printf("{ ");
        for (int k = 0; k < len; k++) printf("%d ", path[k]);
        printf("} ");
        return;
    }
    if (i == N || sum > TARGET) return;           /* dead end -> BACKTRACK */
    path[len] = A[i];
    subset(i + 1, sum + A[i], path, len + 1);     /* choice 1: take A[i]   */
    subset(i + 1, sum, path, len);                /* choice 2: skip A[i]   */
}

int main(void) {
    Node *root = newNode(1, newNode(2, newNode(4, NULL, NULL), newNode(5, NULL, NULL)),
                            newNode(3, NULL, newNode(6, NULL, NULL)));
    printf("BFS (level order): "); bfs(root); printf("\n");
    printf("DFS preorder     : "); preorder(root); printf("\n");
    printf("DFS inorder      : "); inorder(root); printf("\n");
    printf("DFS postorder    : "); postorder(root); printf("\n");

    int path[10];
    printf("Subsets of {3,4,5,6} with sum 9: ");
    subset(0, 0, path, 0);
    printf("\n");
    return 0;
}
