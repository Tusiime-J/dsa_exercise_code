#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ===== 1. Boolean (Java: boolean) ===== */
typedef enum { FALSE = 0, TRUE = 1 } Boolean;

/* ===== 2. String (Java: String) ===== */
typedef struct { char *data; int length; } String;

String str_new(const char *s) {
    String r;
    r.length = strlen(s);
    r.data = malloc(r.length + 1);
    strcpy(r.data, s);
    return r;
}
String str_concat(String a, String b) {
    String r;
    r.length = a.length + b.length;
    r.data = malloc(r.length + 1);
    strcpy(r.data, a.data);
    strcat(r.data, b.data);
    return r;
}
Boolean str_equals(String a, String b) { return strcmp(a.data, b.data) == 0 ? TRUE : FALSE; }
void str_free(String *s) { free(s->data); s->data = NULL; s->length = 0; }

/* ===== 3. ArrayList (Java: ArrayList<Integer>) ===== */
typedef struct { int *data; int size, capacity; } ArrayList;

ArrayList list_new(void) { ArrayList l = { malloc(2 * sizeof(int)), 0, 2 }; return l; }
void list_add(ArrayList *l, int x) {
    if (l->size == l->capacity) {                 /* grow when full */
        l->capacity *= 2;
        l->data = realloc(l->data, l->capacity * sizeof(int));
    }
    l->data[l->size++] = x;
}
int list_get(ArrayList *l, int i) { return l->data[i]; }
void list_remove(ArrayList *l, int i) {
    for (int j = i; j < l->size - 1; j++) l->data[j] = l->data[j + 1];
    l->size--;
}
void list_free(ArrayList *l) { free(l->data); }

int main(void) {
    /* Boolean demo */
    Boolean ok = TRUE;
    printf("Boolean: ok = %s\n", ok ? "true" : "false");

    /* String demo */
    String a = str_new("Hello "), b = str_new("World");
    String c = str_concat(a, b);
    printf("String : '%s' length=%d equals(a,b)=%d\n", c.data, c.length, str_equals(a, b));
    str_free(&a); str_free(&b); str_free(&c);

    /* ArrayList demo */
    ArrayList l = list_new();
    for (int i = 1; i <= 5; i++) list_add(&l, i * 10);   /* 10 20 30 40 50 */
    list_remove(&l, 1);                                  /* remove 20 */
    printf("ArrayList:");
    for (int i = 0; i < l.size; i++) printf(" %d", list_get(&l, i));
    printf("  (size=%d, capacity=%d)\n", l.size, l.capacity);
    list_free(&l);
    return 0;
}
