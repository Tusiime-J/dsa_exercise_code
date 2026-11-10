public class LinearSearch {
    static int steps;                          // counts comparisons

    // Linear search: returns the index of key, or -1
    static int linearSearch(int[] a, int key) {
        steps = 0;
        for (int i = 0; i < a.length; i++) {
            steps++;
            if (a[i] == key) return i;
        }
        return -1;
    }

    public static void main(String[] args) {
        int[] a = {7, 3, 9, 1, 5};

        linearSearch(a, 7);   // key is FIRST
        System.out.println("Best case    (key first)    : " + steps + " comparison  -> O(1)");
        linearSearch(a, 5);   // key is LAST
        System.out.println("Worst case   (key last)     : " + steps + " comparisons -> O(n)");
        linearSearch(a, 8);   // key is NOT present
        System.out.println("Worst case   (key missing)  : " + steps + " comparisons -> O(n)");
        linearSearch(a, 9);   // key in the middle
        System.out.println("Average case (key middle)   : " + steps + " comparisons -> about (n+1)/2");
    }
}
