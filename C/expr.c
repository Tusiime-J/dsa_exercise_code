#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* operator precedence: * and / are stronger than + and - */
int prec(char c) {
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;                                   /* '(' */
}

void reverse(char *s) {
    for (int i = 0, j = strlen(s) - 1; i < j; i++, j--) { char t = s[i]; s[i] = s[j]; s[j] = t; }
}

/* infix -> postfix using a stack of operators (the "shunting-yard" idea)
   forPrefix = 1 is the small tweak needed when converting to prefix       */
void toPostfix(const char *in, char *out, int forPrefix) {
    char st[100]; int top = -1, k = 0;
    for (int i = 0; in[i]; i++) {
        char c = in[i];
        if (isalnum(c)) out[k++] = c;                       /* operand goes straight out */
        else if (c == '(') st[++top] = c;
        else if (c == ')') {
            while (top >= 0 && st[top] != '(') out[k++] = st[top--];
            top--;                                          /* discard '(' */
        } else {                                            /* operator */
            while (top >= 0 && (prec(st[top]) > prec(c) ||
                   (!forPrefix && prec(st[top]) == prec(c))))
                out[k++] = st[top--];
            st[++top] = c;
        }
    }
    while (top >= 0) out[k++] = st[top--];
    out[k] = '\0';
}

/* infix -> prefix: reverse, swap brackets, convert to postfix, reverse again */
void toPrefix(const char *in, char *out) {
    char tmp[100];
    strcpy(tmp, in);
    reverse(tmp);
    for (int i = 0; tmp[i]; i++) {
        if (tmp[i] == '(') tmp[i] = ')'; else if (tmp[i] == ')') tmp[i] = '(';
    }
    toPostfix(tmp, out, 1);
    reverse(out);
}

/* evaluate a postfix expression with single-digit operands */
int evalPostfix(const char *e) {
    int st[100], top = -1;
    for (int i = 0; e[i]; i++) {
        char c = e[i];
        if (isdigit(c)) st[++top] = c - '0';                /* push operand */
        else {
            int b = st[top--], a = st[top--];               /* pop two operands */
            switch (c) {
                case '+': st[++top] = a + b; break;
                case '-': st[++top] = a - b; break;
                case '*': st[++top] = a * b; break;
                case '/': st[++top] = a / b; break;
            }
        }
    }
    return st[top];
}

int main(void) {
    char post[100], pre[100];
    const char *infix = "(A+B)*C-D";
    toPostfix(infix, post, 0);
    toPrefix(infix, pre);
    printf("Infix  : %s\nPostfix: %s\nPrefix : %s\n", infix, post, pre);

    const char *infix2 = "A+B*C";
    toPostfix(infix2, post, 0);
    toPrefix(infix2, pre);
    printf("Infix  : %s  ->  Postfix: %s  Prefix: %s\n", infix2, post, pre);

    printf("Evaluate 23*54*+9- = %d   (2*3 + 5*4 - 9)\n", evalPostfix("23*54*+9-"));
    return 0;
}
