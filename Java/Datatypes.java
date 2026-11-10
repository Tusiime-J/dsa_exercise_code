public class Datatypes {
    // ---- user-defined types ----
    static class Student {                       // class
        int id; String name; double gpa;
        Student(int id, String name, double gpa) { this.id = id; this.name = name; this.gpa = gpa; }
    }
    interface Shape { double area(); }           // interface
    enum Day { MON, TUE, WED }                   // enum
    record Point(int x, int y) {}                // record (Java 16+)

    public static void main(String[] args) {
        // ---- built-in (primitive) types ----
        System.out.println("byte    : " + Byte.BYTES + " byte,  " + Byte.MIN_VALUE + " to " + Byte.MAX_VALUE);
        System.out.println("short   : " + Short.BYTES + " bytes, " + Short.MIN_VALUE + " to " + Short.MAX_VALUE);
        System.out.println("int     : " + Integer.BYTES + " bytes, " + Integer.MIN_VALUE + " to " + Integer.MAX_VALUE);
        System.out.println("long    : " + Long.BYTES + " bytes, " + Long.MIN_VALUE + " to " + Long.MAX_VALUE);
        System.out.println("float   : " + Float.BYTES + " bytes, max " + Float.MAX_VALUE);
        System.out.println("double  : " + Double.BYTES + " bytes, max " + Double.MAX_VALUE);
        System.out.println("char    : " + Character.BYTES + " bytes (Unicode 16-bit)");
        System.out.println("boolean : true / false");

        // ---- reference types ----
        int[] arr = {1, 2, 3};
        String str = "Hello";
        System.out.println("array length " + arr.length + ", String '" + str + "'");

        Student s = new Student(1, "Ann", 3.5);
        System.out.println("class : " + s.id + " " + s.name + " " + s.gpa);
        Shape sq = () -> 4 * 4;
        System.out.println("interface: area = " + sq.area());
        System.out.println("enum  : TUE ordinal = " + Day.TUE.ordinal());
        System.out.println("record: " + new Point(3, 4));
    }
}
