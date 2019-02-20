/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ReadersWriters;

/**
 *
 * @author Mia Carina Friska Lingga
 */
public class Main {
    public static void main(String[] args) {
        Monitor M = new Monitor();
        Reader reader = new Reader("1", M);
        Writer writer = new Writer("1", M);
        reader.start();
        writer.start();
        
    }
}