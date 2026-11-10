#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode { int val; struct ListNode *next; } ListNode;

ListNode *newNode(int v) {
    ListNode *n = malloc(sizeof(ListNode));
    n->val = v; n->next = NULL;
    return n;
}

/* digits are stored least-significant first: 99 -> 9 -> 9 -> NULL */
ListNode *multiplyLinkedList(ListNode *head, int k) {
    if (head == NULL || k == 0) return newNode(0);   /* anything x 0 = 0 */
    ListNode *result = NULL, *tail = NULL;
    int carry = 0;
    for (ListNode *p = head; p != NULL; p = p->next) {
        int prod = p->val * k + carry;               /* digit * k + carry */
        ListNode *n = newNode(prod % 10);            /* keep last digit   */
        carry = prod / 10;                           /* pass the rest on  */
        if (!result) result = tail = n; else { tail->next = n; tail = n; }
    }
    while (carry > 0) {                              /* leftover carry becomes new digits */
        tail->next = newNode(carry % 10);
        tail = tail->next;
        carry /= 10;
    }
    return result;
}

ListNode *fromArray(int a[], int n) {
    ListNode *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++) {
        ListNode *x = newNode(a[i]);
        if (!head) head = tail = x; else { tail->next = x; tail = x; }
    }
    return head;
}
void print(ListNode *h) {
    for (; h; h = h->next) printf("[%d] -> ", h->val);
    printf("null\n");
}

int main(void) {
    int d[] = {9, 9};                    /* 99 */
    ListNode *h = fromArray(d, 2);
    printf("Input : "); print(h);
    printf("k = 5\nOutput: "); print(multiplyLinkedList(h, 5));   /* 495 -> 5,9,4 */

    int e[] = {3, 2, 1};                 /* 123 */
    printf("123 x 10 = "); print(multiplyLinkedList(fromArray(e, 3), 10));  /* 1230 -> 0,3,2,1 */
    printf("123 x 0  = "); print(multiplyLinkedList(fromArray(e, 3), 0));   /* 0 */
    return 0;
}
