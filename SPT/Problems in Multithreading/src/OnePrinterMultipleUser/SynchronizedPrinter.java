/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package OnePrinterMultipleUser;

import java.util.concurrent.Semaphore;
import java.io.PrintStream;

/**
 *
 * @author Mia Carina Friska Lingga
 */
public class SynchronizedPrinter extends Printer{
    private Semaphore s = null;
    
    public SynchronizedPrinter(PrintStream _stream, long _delay){
        super(_stream, _delay);
        s = new Semaphore(1);
    }
    @Override
    public void print(String _document){
        int documentLength = _document.length();
        (new Thread(new Runnable(){
             @Override
    public void run(){
        try{
            s.acquire();
            for (int index = 0; index < documentLength; ++index){
                stream.println( _document.charAt(index));
                
                Thread.sleep(delay);
            }
            s.release();
        } catch (InterruptedException ex){
            ex.printStackTrace();
        }
    }
    })).start();
  }
}