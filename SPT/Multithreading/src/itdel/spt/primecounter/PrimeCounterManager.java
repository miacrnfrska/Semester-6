/*
* SPT (18/19) - Institut Teknologi Del
 */
package itdel.spt.primecounter;

import java.util.ArrayList;
import java.util.List;

public class PrimeCounterManager {

    private long min = 0L;
    private long max = 0L;
    private int numWorker = 0;
    private List<ThreadedPrimeCounter> workers;

    public PrimeCounterManager(long _min, long _max, int _numWorker) {
        min = (_min > 0) ? _min : 1L;
        max = _max;
        numWorker = _numWorker;
        max = (_max > 0) ? _max : 2L;
        workers = new ArrayList<ThreadedPrimeCounter>(numWorker);
    }

    public void count() {
        long width = (max - min) / numWorker;
        long start = min;
        long end = 0;
        for (int counterWorker = 0; counterWorker < numWorker; ++counterWorker) {
            if (counterWorker < numWorker - 1) {
                end = start + width;
            } else {
                end = max;
            }
            ThreadedPrimeCounter pc = new ThreadedPrimeCounter(start, end);
            start = end + 1;
            workers.add(pc);
            pc.count();
        }
    }
}
