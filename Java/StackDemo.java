public class StackDemo {
    // ===== Stack using an ARRAY =====
    static class ArrayStack {
        int[] data = new int[5];
        int top = -1;
        boolean isEmpty() { return top == -1; }
        boolean isFull()  { return top == data.length - 1; }
        void push(int x) {
            if (isFull()) { System.out.println("Overflow"); return; }
            data[++top] = x;
        }
        int pop() {
            if (isEmpty()) { System.out.println("Underflow"); return -1; }
            return data[top--];
        }
        int peek() { return isEmpty() ? -1 : data[top]; }
    }

    // ===== Stack using a LINKED LIST =====
    static class Node { int data; Node next; Node(int d) { data = d; } }
    static class ListStack {
        Node top;
        void push(int x) {
            Node n = new Node(x);
            n.next = top;          // new node points to old top
            top = n;               // new node becomes the top
        }
        int pop() {
            if (top == null) { System.out.println("Underflow"); return -1; }
            int x = top.data;
            top = top.next;
            return x;
        }
        int peek() { return top == null ? -1 : top.data; }
    }

    public static void main(String[] args) {
        ArrayStack as = new ArrayStack();
        as.push(10); as.push(20); as.push(30);
        System.out.println("Array stack : peek=" + as.peek() + ", pop=" + as.pop() + ", pop=" + as.pop());

        ListStack ls = new ListStack();
        ls.push(10); ls.push(20); ls.push(30);
        System.out.println("List stack  : peek=" + ls.peek() + ", pop=" + ls.pop() + ", pop=" + ls.pop());
    }
}
