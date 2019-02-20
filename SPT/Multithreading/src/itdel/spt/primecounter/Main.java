/*
* SPT (18/19) - Institut Teknologi Del
 */
package itdel.spt.primecounter;

import itdel.spt.utils.Stopwatch;

public class Main {

    public static void main(String _args[]) {
        Stopwatch stopwatch = new Stopwatch();
        long elapsedTime = 0L;
        long min = 0L;
        long max = 10000L;
        PrimeCounter pc = new PrimeCounter(min, max);
        stopwatch.record();
        pc.count();
        elapsedTime = stopwatch.capture();
        System.out.printf("finished in %d sec(s)\n", elapsedTime);
    }
}
