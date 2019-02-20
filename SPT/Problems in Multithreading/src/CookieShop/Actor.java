/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package CookieShop;

/**
 *
 * @author Mia Carina Friska Lingga
 */
public abstract class Actor implements Runnable {
    protected final String name;
    protected final CookieJar jar;
    protected final long delay;
    private int cycle = 0;
    
    public Actor(String _name, CookieJar _jar, long _delay){
        name = _name;
        jar = _jar;
        delay = _delay;
    }
    
    public String getName(){
        return (name);
    }
    public void setCycle(int _cycle){
        cycle = _cycle;
    }
    
    @Override
    public void run(){
        int counter = 0;
        while (counter < cycle){
            work();
            try{
                Thread.sleep(delay);
            }catch (InterruptedException ie){
                ie.printStackTrace();
            }
            ++counter;
        }
    }
    public void say(String _massage){
        System.out.println(name + ": " + _massage);
    }
    public abstract void work();
}
