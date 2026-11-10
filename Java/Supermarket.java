import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class Supermarket {
    static final int N = 3;                                  // number of checkout counters
    static List<Queue<String>> counters = new ArrayList<>();

    // CustomerArrival: join the SHORTEST queue (ties -> lowest counter number)
    static void customerArrival(String name) {
        int best = 0;
        for (int i = 1; i < N; i++)
            if (counters.get(i).size() < counters.get(best).size()) best = i;  // strict < keeps the first on ties
        counters.get(best).add(name);
        System.out.println(name + " joins counter " + (best + 1));
    }

    // ProcessNextCustomer: serve the FRONT customer of a counter (FIFO)
    static void processNextCustomer(int counterNumber) {
        String who = counters.get(counterNumber - 1).poll();
        if (who == null) System.out.println("Counter " + counterNumber + " is empty");
        else System.out.println("Counter " + counterNumber + " serves " + who);
    }

    // DisplayQueue: print the queue from front to rear
    static void displayQueue(int counterNumber) {
        Queue<String> q = counters.get(counterNumber - 1);
        System.out.println("Counter " + counterNumber + ": " + (q.isEmpty() ? "(empty)" : String.join(" ", q)));
    }

    public static void main(String[] args) {
        for (int i = 0; i < N; i++) counters.add(new LinkedList<>());
        customerArrival("Ann"); customerArrival("Ben"); customerArrival("Cat");
        customerArrival("Dan"); customerArrival("Eve");
        for (int i = 1; i <= N; i++) displayQueue(i);
        processNextCustomer(1);
        displayQueue(1);
        customerArrival("Fay");                              // counter 1 is shortest again
        for (int i = 1; i <= N; i++) displayQueue(i);
    }
}
