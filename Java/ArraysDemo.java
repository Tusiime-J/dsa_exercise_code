public class ArraysDemo {
    // Java hides real memory addresses, so we SIMULATE a base address (1000) and
    // use the same formulas. Element size of int = 4 bytes.
    static final long BASE = 1000;
    static final int SIZE = 4;

    // (d) minimum and maximum of a 2D array with locations
    static int[] findMin(int[][] a) {            // returns {value, row, col}
        int[] best = {a[0][0], 0, 0};
        for (int i = 0; i < a.length; i++)
            for (int j = 0; j < a[i].length; j++)
                if (a[i][j] < best[0]) best = new int[]{a[i][j], i, j};
        return best;
    }
    static int[] findMax(int[][] a) {
        int[] best = {a[0][0], 0, 0};
        for (int i = 0; i < a.length; i++)
            for (int j = 0; j < a[i].length; j++)
                if (a[i][j] > best[0]) best = new int[]{a[i][j], i, j};
        return best;
    }

    public static void main(String[] args) {
        // (b) 1D: address = base + i * size
        int[] a = {10, 20, 30, 40, 50};
        System.out.println("--- 1D --- base = " + BASE);
        for (int i = 0; i < a.length; i++)
            System.out.println("a[" + i + "]=" + a[i] + "  address=" + (BASE + (long) i * SIZE));

        // 2D (row-major): address = base + (i*COLS + j) * size
        int[][] b = {{1, 2, 3}, {4, 5, 6}};
        int COLS = 3;
        System.out.println("--- 2D --- base = " + BASE);
        for (int i = 0; i < b.length; i++)
            for (int j = 0; j < b[i].length; j++)
                System.out.println("b[" + i + "][" + j + "]=" + b[i][j] + "  address=" + (BASE + (long) (i * COLS + j) * SIZE));

        // 3D: address = base + ((i*R + j)*C + k) * size
        int[][][] c = {{{1, 2}, {3, 4}}, {{5, 6}, {7, 8}}};
        System.out.println("--- 3D --- base = " + BASE);
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                for (int k = 0; k < 2; k++)
                    System.out.println("c[" + i + "][" + j + "][" + k + "]=" + c[i][j][k]
                            + "  address=" + (BASE + (long) ((i * 2 + j) * 2 + k) * SIZE));

        // (c) merge two 1D arrays (sorted merge)
        int[] x = {1, 3, 5}, y = {2, 4, 6, 8}, m = new int[x.length + y.length];
        int i = 0, j = 0, k = 0;
        while (i < x.length && j < y.length) m[k++] = (x[i] <= y[j]) ? x[i++] : y[j++];
        while (i < x.length) m[k++] = x[i++];
        while (j < y.length) m[k++] = y[j++];
        System.out.println("--- merge --- " + java.util.Arrays.toString(m));

        // (d) min and max with location
        int[][] g = {{7, 2, 9}, {4, 11, 1}};
        int[] mn = findMin(g), mx = findMax(g);
        System.out.println("--- min/max --- min=" + mn[0] + " at (" + mn[1] + "," + mn[2] + ")  max="
                + mx[0] + " at (" + mx[1] + "," + mx[2] + ")");
    }
}
