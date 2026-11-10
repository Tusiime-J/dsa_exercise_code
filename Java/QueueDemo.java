public class QueueDemo {
    // ===== Queue using a (circular) ARRAY =====
    static class ArrayQueue {
        int[] data = new int[5];
        int front = 0, rear = -1, count = 0;
        void enqueue(int x) {
            if (count == data.length) { System.out.println("Queue full"); return; }
            rear = (rear + 1) % data.length;      // wrap around
            data[rear] = x;
            count++;
        }
        int dequeue() {
            if (count == 0) { System.out.println("Queue empty"); return -1; }
            int x = data[front];
            front = (front + 1) % data.length;
            count--;
            return x;
        }
    }

    // ===== Queue using a LINKED LIST =====
    static class Node { int data; Node next; Node(int d) { data = d; } }
    static class ListQueue {
        Node front, rear;
        void enqueue(int x) {
            Node n = new Node(x);
            if (rear != null) rear.next = n; else front = n;   // first node is also front
            rear = n;
        }
        int dequeue() {
            if (front == null) { System.out.println("Queue empty"); return -1; }
            int x = front.data;
            front = front.next;
            if (front == null) rear = null;
            return x;
        }
    }

    public static void main(String[] args) {
        ArrayQueue aq = new ArrayQueue();
        aq.enqueue(1); aq.enqueue(2); aq.enqueue(3);
        System.out.println("Array queue : dequeue=" + aq.dequeue() + ", dequeue=" + aq.dequeue());  // 1 then 2 (FIFO)

        ListQueue lq = new ListQueue();
        lq.enqueue(1); lq.enqueue(2); lq.enqueue(3);
        System.out.println("List queue  : dequeue=" + lq.dequeue() + ", dequeue=" + lq.dequeue());
    }
}
