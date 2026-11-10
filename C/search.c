#include <stdio.h>

/* Linear search: returns the index of key, or -1. 'steps' counts comparisons. */
int linearSearch(int a[], int n, int key, int *steps) {
    *steps = 0;
    for (int i = 0; i < n; i++) {
        (*steps)++;
        if (a[i] == key) return i;
    }
    return -1;
}

int main(void) {
    int a[] = {7, 3, 9, 1, 5};
    int n = 5, steps;

    linearSearch(a, n, 7, &steps);   /* key is FIRST          */
    printf("Best case    (key first)    : %d comparison  -> O(1)\n", steps);
    linearSearch(a, n, 5, &steps);   /* key is LAST           */
    printf("Worst case   (key last)     : %d comparisons -> O(n)\n", steps);
    linearSearch(a, n, 8, &steps);   /* key is NOT present    */
    printf("Worst case   (key missing)  : %d comparisons -> O(n)\n", steps);
    linearSearch(a, n, 9, &steps);   /* key in the middle     */
    printf("Average case (key middle)   : %d comparisons -> about (n+1)/2\n", steps);
    return 0;
}
