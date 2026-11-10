#include <stdio.h>
#define ROWS 2
#define COLS 3

/* (d) minimum and maximum of a 2D array with their locations */
int findMin(int a[ROWS][COLS], int *row, int *col) {
    int min = a[0][0]; *row = 0; *col = 0;
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            if (a[i][j] < min) { min = a[i][j]; *row = i; *col = j; }
    return min;
}
int findMax(int a[ROWS][COLS], int *row, int *col) {
    int max = a[0][0]; *row = 0; *col = 0;
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            if (a[i][j] > max) { max = a[i][j]; *row = i; *col = j; }
    return max;
}

int main(void) {
    /* (b) 1D traversal: address(a[i]) = base + i * size */
    int a[5] = {10, 20, 30, 40, 50};
    printf("--- 1D --- base address = %p\n", (void *)a);
    for (int i = 0; i < 5; i++)
        printf("a[%d]=%d  actual=%p  formula=%p\n", i, a[i], (void *)&a[i],
               (void *)((char *)a + i * sizeof(int)));

    /* 2D traversal (row-major): address(b[i][j]) = base + (i*COLS + j) * size */
    int b[ROWS][COLS] = {{1, 2, 3}, {4, 5, 6}};
    printf("--- 2D --- base address = %p\n", (void *)b);
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            printf("b[%d][%d]=%d  actual=%p  formula=%p\n", i, j, b[i][j], (void *)&b[i][j],
                   (void *)((char *)b + (i * COLS + j) * sizeof(int)));

    /* 3D traversal: address(c[i][j][k]) = base + ((i*R + j)*C + k) * size */
    int c[2][2][2] = {{{1, 2}, {3, 4}}, {{5, 6}, {7, 8}}};
    printf("--- 3D --- base address = %p\n", (void *)c);
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                printf("c[%d][%d][%d]=%d  actual=%p  formula=%p\n", i, j, k, c[i][j][k],
                       (void *)&c[i][j][k], (void *)((char *)c + ((i * 2 + j) * 2 + k) * sizeof(int)));

    /* (c) merge two 1D arrays into one */
    int x[3] = {1, 3, 5}, y[4] = {2, 4, 6, 8}, m[7];
    int i = 0, j = 0, k = 0;
    while (i < 3 && j < 4) m[k++] = (x[i] <= y[j]) ? x[i++] : y[j++];  /* sorted merge */
    while (i < 3) m[k++] = x[i++];
    while (j < 4) m[k++] = y[j++];
    printf("--- merge --- ");
    for (k = 0; k < 7; k++) printf("%d ", m[k]);
    printf("\n");

    /* (d) min and max with location */
    int g[ROWS][COLS] = {{7, 2, 9}, {4, 11, 1}};
    int r, cl;
    int mn = findMin(g, &r, &cl);
    printf("--- min/max --- min=%d at (%d,%d)  ", mn, r, cl);
    int mx = findMax(g, &r, &cl);
    printf("max=%d at (%d,%d)\n", mx, r, cl);
    return 0;
}
