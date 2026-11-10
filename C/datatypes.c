#include <stdio.h>
#include <limits.h>
#include <float.h>

struct Student { int id; char name[20]; float gpa; };   /* struct  */
union  Number  { int i; float f; };                     /* union   */
enum   Day     { MON, TUE, WED };                       /* enum    */
typedef struct { int x, y; } Point;                     /* typedef */

int main(void) {
    /* ---- built-in (primitive) types ---- */
    printf("char   : %zu byte,  %d to %d\n", sizeof(char), CHAR_MIN, CHAR_MAX);
    printf("short  : %zu bytes, %d to %d\n", sizeof(short), SHRT_MIN, SHRT_MAX);
    printf("int    : %zu bytes, %d to %d\n", sizeof(int), INT_MIN, INT_MAX);
    printf("long   : %zu bytes, %ld to %ld\n", sizeof(long), LONG_MIN, LONG_MAX);
    printf("float  : %zu bytes, max %e\n", sizeof(float), FLT_MAX);
    printf("double : %zu bytes, max %e\n", sizeof(double), DBL_MAX);

    /* ---- derived types ---- */
    int arr[3] = {1, 2, 3};
    int *p = &arr[0];
    printf("array: %d %d %d, pointer *p = %d\n", arr[0], arr[1], arr[2], *p);

    /* ---- user-defined types ---- */
    struct Student s = {1, "Ann", 3.5f};
    printf("struct: %d %s %.1f\n", s.id, s.name, s.gpa);

    union Number n;
    n.i = 7;
    printf("union : n.i = %d (shares memory with n.f)\n", n.i);

    enum Day d = TUE;
    printf("enum  : TUE = %d\n", d);

    Point pt = {3, 4};
    printf("typedef: Point(%d, %d)\n", pt.x, pt.y);
    return 0;
}
