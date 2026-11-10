import java.util.ArrayDeque;
import java.util.Deque;

public class ExprDemo {
    // operator precedence: * and / are stronger than + and -
    static int prec(char c) {
        if (c == '*' || c == '/') return 2;
        if (c == '+' || c == '-') return 1;
        return 0;                                   // '('
    }

    // infix -> postfix using a stack of operators
    // forPrefix = true is the small tweak needed when converting to prefix
    static String toPostfix(String in, boolean forPrefix) {
        StringBuilder out = new StringBuilder();
        Deque<Character> st = new ArrayDeque<>();
        for (char c : in.toCharArray()) {
            if (Character.isLetterOrDigit(c)) out.append(c);       // operand goes straight out
            else if (c == '(') st.push(c);
            else if (c == ')') {
                while (!st.isEmpty() && st.peek() != '(') out.append(st.pop());
                st.pop();                                           // discard '('
            } else {                                                // operator
                while (!st.isEmpty() && (prec(st.peek()) > prec(c) ||
                        (!forPrefix && prec(st.peek()) == prec(c))))
                    out.append(st.pop());
                st.push(c);
            }
        }
        while (!st.isEmpty()) out.append(st.pop());
        return out.toString();
    }

    // infix -> prefix: reverse, swap brackets, convert to postfix, reverse again
    static String toPrefix(String in) {
        StringBuilder r = new StringBuilder(in).reverse();
        for (int i = 0; i < r.length(); i++) {
            if (r.charAt(i) == '(') r.setCharAt(i, ')');
            else if (r.charAt(i) == ')') r.setCharAt(i, '(');
        }
        return new StringBuilder(toPostfix(r.toString(), true)).reverse().toString();
    }

    // evaluate a postfix expression with single-digit operands
    static int evalPostfix(String e) {
        Deque<Integer> st = new ArrayDeque<>();
        for (char c : e.toCharArray()) {
            if (Character.isDigit(c)) st.push(c - '0');            // push operand
            else {
                int b = st.pop(), a = st.pop();                    // pop two operands
                switch (c) {
                    case '+' -> st.push(a + b);
                    case '-' -> st.push(a - b);
                    case '*' -> st.push(a * b);
                    case '/' -> st.push(a / b);
                }
            }
        }
        return st.pop();
    }

    public static void main(String[] args) {
        String infix = "(A+B)*C-D";
        System.out.println("Infix  : " + infix);
        System.out.println("Postfix: " + toPostfix(infix, false));
        System.out.println("Prefix : " + toPrefix(infix));

        String infix2 = "A+B*C";
        System.out.println("Infix  : " + infix2 + "  ->  Postfix: " + toPostfix(infix2, false)
                + "  Prefix: " + toPrefix(infix2));

        System.out.println("Evaluate 23*54*+9- = " + evalPostfix("23*54*+9-") + "   (2*3 + 5*4 - 9)");
    }
}
