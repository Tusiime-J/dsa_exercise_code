#include <stdio.h>
#include <stdlib.h>
#define MAX 5

/* ===== Queue using a (circular) ARRAY ===== */
typedef struct { int data[MAX]; int front, rear, count; } ArrayQueue;

void a_init(ArrayQueue *q) { q->front = 0; q->rear = -1; q->count = 0; }
void a_enqueue(ArrayQueue *q, int x) {
    if (q->count == MAX) { printf("Queue full\n"); return; }
    q->rear = (q->rear + 1) % MAX;        /* wrap around */
    q->data[q->rear] = x;
    q->count++;
}
int a_dequeue(ArrayQueue *q) {
    if (q->count == 0) { printf("Queue empty\n"); return -1; }
    int x = q->data[q->front];
    q->front = (q->front + 1) % MAX;
    q->count--;
    return x;
}

/* ===== Queue using a LINKED LIST ===== */
typedef struct Node { int data; struct Node *next; } Node;
typedef struct { Node *front, *rear; } ListQueue;

void l_enqueue(ListQueue *q, int x) {
    Node *n = malloc(sizeof(Node));
    n->data = x; n->next = NULL;
    if (q->rear) q->rear->next = n; else q->front = n;   /* first node is also front */
    q->rear = n;
}
int l_dequeue(ListQueue *q) {
    if (q->front == NULL) { printf("Queue empty\n"); return -1; }
    Node *t = q->front;
    int x = t->data;
    q->front = t->next;
    if (q->front == NULL) q->rear = NULL;
    free(t);
    return x;
}

int main(void) {
    ArrayQueue aq; a_init(&aq);
    a_enqueue(&aq, 1); a_enqueue(&aq, 2); a_enqueue(&aq, 3);
    int x1 = a_dequeue(&aq), x2 = a_dequeue(&aq);             /* 1 then 2 (FIFO) */
    printf("Array queue : dequeue=%d, dequeue=%d\n", x1, x2);

    ListQueue lq = { NULL, NULL };
    l_enqueue(&lq, 1); l_enqueue(&lq, 2); l_enqueue(&lq, 3);
    int y1 = l_dequeue(&lq), y2 = l_dequeue(&lq);
    printf("List queue  : dequeue=%d, dequeue=%d\n", y1, y2);
    return 0;
}
