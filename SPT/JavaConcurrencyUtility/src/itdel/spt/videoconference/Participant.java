/*
    SPT (18/19) - Institut Teknologi Del
    Nama  : Mia Carina Friska Lingga
    NIM   : 11S16059
    Kelas : 13TI2
 */

package itdel.spt.videoconference;

import java.util.concurrent.TimeUnit;

public class Participant implements Runnable {

    private final VideoConference conference;
    private final String name;

    public Participant(VideoConference conference, String name) {
        this.conference = conference;
        this.name = name;
    }

    @Override
    public void run() {
        long duration = (long) (Math.random() * 10);
        try {
            TimeUnit.SECONDS.sleep(duration);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        conference.arrive(name);
    }
}
