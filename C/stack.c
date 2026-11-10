#include <stdio.h>
#include <stdlib.h>
#define MAX 5

/* ===== Stack using an ARRAY ===== */
typedef struct { int data[MAX]; int top; } ArrayStack;

void a_init(ArrayStack *s) { s->top = -1; }
int  a_isEmpty(ArrayStack *s) { return s->top == -1; }
int  a_isFull(ArrayStack *s) { return s->top == MAX - 1; }
void a_push(ArrayStack *s, int x) {
    if (a_isFull(s)) { printf("Overflow\n"); return; }
    s->data[++s->top] = x;
}
int a_pop(ArrayStack *s) {
    if (a_isEmpty(s)) { printf("Underflow\n"); return -1; }
    return s->data[s->top--];
}
int a_peek(ArrayStack *s) { return a_isEmpty(s) ? -1 : s->data[s->top]; }

/* ===== Stack using a LINKED LIST ===== */
typedef struct Node { int data; struct Node *next; } Node;
typedef struct { Node *top; } ListStack;

void l_push(ListStack *s, int x) {
    Node *n = malloc(sizeof(Node));
    n->data = x;
    n->next = s->top;          /* new node points to old top */
    s->top = n;                /* new node becomes the top   */
}
int l_pop(ListStack *s) {
    if (s->top == NULL) { printf("Underflow\n"); return -1; }
    Node *t = s->top;
    int x = t->data;
    s->top = t->next;
    free(t);
    return x;
}
int l_peek(ListStack *s) { return s->top ? s->top->data : -1; }

int main(void) {
    ArrayStack as; a_init(&as);
    a_push(&as, 10); a_push(&as, 20); a_push(&as, 30);
    int p1 = a_peek(&as), p2 = a_pop(&as), p3 = a_pop(&as);   /* separate statements = fixed order */
    printf("Array stack : peek=%d, pop=%d, pop=%d\n", p1, p2, p3);

    ListStack ls = { NULL };
    l_push(&ls, 10); l_push(&ls, 20); l_push(&ls, 30);
    int q1 = l_peek(&ls), q2 = l_pop(&ls), q3 = l_pop(&ls);
    printf("List stack  : peek=%d, pop=%d, pop=%d\n", q1, q2, q3);
    return 0;
}
