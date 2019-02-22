/*
    SPT (18/19) - Institut Teknologi Del
    Nama  : Mia Carina Friska Lingga
    NIM   : 11S16059
    Kelas : 13TI2
 */

package itdel.spt.matrixmock;

public class Results {

    private final int data[];

    public Results(int size) {
        data = new int[size];
    }

    public void setData(int position, int value) {
        data[position] = value;
    }

    public int[] getData() {
        return data;
    }
}
