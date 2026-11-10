public class MultiplyList {
    static class ListNode {
        int val; ListNode next;
        ListNode(int v) { val = v; }
    }

    // digits are stored least-significant first: 99 -> 9 -> 9 -> null
    static ListNode multiplyLinkedList(ListNode head, int k) {
        if (head == null || k == 0) return new ListNode(0);   // anything x 0 = 0
        ListNode dummy = new ListNode(-1), tail = dummy;
        int carry = 0;
        for (ListNode p = head; p != null; p = p.next) {
            int prod = p.val * k + carry;                     // digit * k + carry
            tail.next = new ListNode(prod % 10);              // keep last digit
            tail = tail.next;
            carry = prod / 10;                                // pass the rest on
        }
        while (carry > 0) {                                   // leftover carry -> new digits
            tail.next = new ListNode(carry % 10);
            tail = tail.next;
            carry /= 10;
        }
        return dummy.next;
    }

    static ListNode fromArray(int... a) {
        ListNode dummy = new ListNode(-1), tail = dummy;
        for (int x : a) { tail.next = new ListNode(x); tail = tail.next; }
        return dummy.next;
    }
    static void print(ListNode h) {
        for (; h != null; h = h.next) System.out.print("[" + h.val + "] -> ");
        System.out.println("null");
    }

    public static void main(String[] args) {
        ListNode h = fromArray(9, 9);                         // 99
        System.out.print("Input : "); print(h);
        System.out.print("k = 5\nOutput: "); print(multiplyLinkedList(h, 5));   // 495 -> 5,9,4
        System.out.print("123 x 10 = "); print(multiplyLinkedList(fromArray(3, 2, 1), 10)); // 0,3,2,1
        System.out.print("123 x 0  = "); print(multiplyLinkedList(fromArray(3, 2, 1), 0));  // 0
    }
}
