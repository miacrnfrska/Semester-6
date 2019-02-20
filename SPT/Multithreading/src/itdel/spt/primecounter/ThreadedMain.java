/*
* SPT (18/19) - Institut Teknologi Del
 */
package itdel.spt.primecounter;

import itdel.spt.utils.Stopwatch;

public class ThreadedMain {

    public static void main(String _args[]) {
        Stopwatch stopwatch = new Stopwatch();
        long elapsedTime = 0L;
        long min = 0L;
        long max = 1000000;
        int numWorker = 4;
        PrimeCounterManager pcm
                = new PrimeCounterManager(min, max, numWorker);
        stopwatch.record();
        pcm.count();
        elapsedTime = stopwatch.capture();
        System.out.printf("finished in %d sec(s)\n", elapsedTime);
    }
}
