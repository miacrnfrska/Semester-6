/*
   SPT (18/19) - Institut Teknologi Del
   Nama    :  Mia Carina Friska Lingga
   NIM     : 11S16059
*/

package itdel.spt.printjob;

public class Main {

    public static void main(String args[]) {
        PrintQueue printQueue = new PrintQueue();
        Thread[] threads = new Thread[12];
        for (int i = 0; i < threads.length; i++) {
            threads[i] = new Thread(new Job(printQueue), "Thread" + i);
        }
        for (int i = 0; i < threads.length; i++) {
            threads[i].start();
        }
    }
}
