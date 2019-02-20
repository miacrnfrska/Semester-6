/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package OnePrinterMultipleUser;
import java.io.PrintStream;
/**
 *
 * @author Mia Carina Friska Lingga
 */
public class Printer {
    protected PrintStream stream = null;
    protected long delay = 0;
    
    public Printer(PrintStream _stream, long _delay){
        stream = _stream;
        delay = _delay;
    }
    
    public void print(String _document){
        int documentLength = _document.length();
        (new Thread(new Runnable(){
            @Override
            public void run(){
                for (int index = 0; index < documentLength; ++index){
                    stream.println( _document.charAt(index));
                    try{
                        Thread.sleep(delay);
                    } catch (InterruptedException ex){
                        ex.printStackTrace();
                    }
                }
            }
        })).start();
    }   
}
