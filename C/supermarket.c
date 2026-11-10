#include <stdio.h>
#include <string.h>
#define N 3          /* number of checkout counters */
#define MAXQ 10      /* max customers per queue     */

typedef struct { char name[MAXQ][20]; int front, count; } Queue;
Queue counters[N];

void enqueue(Queue *q, const char *who) {
    int rear = (q->front + q->count) % MAXQ;
    strcpy(q->name[rear], who);
    q->count++;
}

/* CustomerArrival: join the SHORTEST queue (ties -> lowest counter number) */
void CustomerArrival(const char *customer_name) {
    int best = 0;
    for (int i = 1; i < N; i++)
        if (counters[i].count < counters[best].count) best = i;   /* strict < keeps the first on ties */
    enqueue(&counters[best], customer_name);
    printf("%s joins counter %d\n", customer_name, best + 1);
}

/* ProcessNextCustomer: serve the FRONT customer of a counter (FIFO) */
void ProcessNextCustomer(int counter_number) {
    Queue *q = &counters[counter_number - 1];
    if (q->count == 0) { printf("Counter %d is empty\n", counter_number); return; }
    printf("Counter %d serves %s\n", counter_number, q->name[q->front]);
    q->front = (q->front + 1) % MAXQ;
    q->count--;
}

/* DisplayQueue: print the queue from front to rear */
void DisplayQueue(int counter_number) {
    Queue *q = &counters[counter_number - 1];
    printf("Counter %d: ", counter_number);
    if (q->count == 0) printf("(empty)");
    for (int i = 0; i < q->count; i++) printf("%s ", q->name[(q->front + i) % MAXQ]);
    printf("\n");
}

int main(void) {
    CustomerArrival("Ann"); CustomerArrival("Ben"); CustomerArrival("Cat");
    CustomerArrival("Dan"); CustomerArrival("Eve");
    for (int i = 1; i <= N; i++) DisplayQueue(i);
    ProcessNextCustomer(1);
    DisplayQueue(1);
    CustomerArrival("Fay");              /* counter 1 is shortest again */
    for (int i = 1; i <= N; i++) DisplayQueue(i);
    return 0;
}
