import java.util.ArrayDeque;
import java.util.Queue;

public class TreeDemo {
    /*        1
             / \
            2   3
           / \   \
          4   5   6        */
    static class Node {
        int val; Node left, right;
        Node(int v, Node l, Node r) { val = v; left = l; right = r; }
    }

    // ---------- DFS: go deep first (recursion = the system stack) ----------
    static void preorder(Node n)  { if (n == null) return; System.out.print(n.val + " "); preorder(n.left); preorder(n.right); }
    static void inorder(Node n)   { if (n == null) return; inorder(n.left); System.out.print(n.val + " "); inorder(n.right); }
    static void postorder(Node n) { if (n == null) return; postorder(n.left); postorder(n.right); System.out.print(n.val + " "); }

    // ---------- BFS: level by level (uses a QUEUE) ----------
    static void bfs(Node root) {
        Queue<Node> q = new ArrayDeque<>();
        q.add(root);
        while (!q.isEmpty()) {
            Node n = q.remove();                       // dequeue
            System.out.print(n.val + " ");
            if (n.left != null) q.add(n.left);         // enqueue children
            if (n.right != null) q.add(n.right);
        }
    }

    // ---------- Backtracking (DFS on a decision tree): subset sum ----------
    static int[] A = {3, 4, 5, 6};
    static int TARGET = 9;
    static void subset(int i, int sum, String path) {
        if (sum == TARGET) { System.out.print("{ " + path + "} "); return; }   // solution found
        if (i == A.length || sum > TARGET) return;                             // dead end -> BACKTRACK
        subset(i + 1, sum + A[i], path + A[i] + " ");  // choice 1: take A[i]
        subset(i + 1, sum, path);                      // choice 2: skip A[i]
    }

    public static void main(String[] args) {
        Node root = new Node(1, new Node(2, new Node(4, null, null), new Node(5, null, null)),
                                new Node(3, null, new Node(6, null, null)));
        System.out.print("BFS (level order): "); bfs(root); System.out.println();
        System.out.print("DFS preorder     : "); preorder(root); System.out.println();
        System.out.print("DFS inorder      : "); inorder(root); System.out.println();
        System.out.print("DFS postorder    : "); postorder(root); System.out.println();
        System.out.print("Subsets of {3,4,5,6} with sum 9: "); subset(0, 0, ""); System.out.println();
    }
}
