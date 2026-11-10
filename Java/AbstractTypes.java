import java.util.ArrayList;

// The same three types in Java: they are built in, so we just use them.
public class AbstractTypes {
    public static void main(String[] args) {
        // boolean
        boolean ok = true;
        System.out.println("boolean: ok = " + ok);

        // String
        String a = "Hello ", b = "World";
        String c = a.concat(b);
        System.out.println("String : '" + c + "' length=" + c.length() + " equals(a,b)=" + a.equals(b));

        // ArrayList
        ArrayList<Integer> l = new ArrayList<>();
        for (int i = 1; i <= 5; i++) l.add(i * 10);   // 10 20 30 40 50
        l.remove(1);                                  // remove index 1 (value 20)
        System.out.println("ArrayList: " + l + " (size=" + l.size() + ")");
    }
}
