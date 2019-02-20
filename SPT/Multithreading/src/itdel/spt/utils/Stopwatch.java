/*
* SPT (18/19) - Institut Teknologi Del
 */
package itdel.spt.utils;

import java.util.Calendar;

public class Stopwatch {

    private long record;

    public long getTime() {
        return (Calendar.getInstance().getTimeInMillis());
    }

    public void record() {
        record = getTime();
    }

    public long capture() {
        return ((getTime() - record) / 1000L);
    }
}
