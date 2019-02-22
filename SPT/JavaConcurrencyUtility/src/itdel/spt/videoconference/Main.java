/*
    SPT (18/19) - Institut Teknologi Del
    Nama  : Mia Carina Friska Lingga
    NIM   : 11S16059
    Kelas : 13TI2
 */

package itdel.spt.videoconference;

public class Main {

    public static void main(String[] args) {
        VideoConference conference = new VideoConference(10);
        Thread threadConference = new Thread(conference);
        threadConference.start();
        for (int i = 0; i < 10; i++) {
            Participant p = new Participant(conference, "Participant " + i);
            Thread t = new Thread(p);
            t.start();
        }
    }
}