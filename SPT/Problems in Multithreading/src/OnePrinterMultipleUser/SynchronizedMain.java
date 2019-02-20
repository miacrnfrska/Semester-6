/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package OnePrinterMultipleUser;

/**
 *
 * @author Mia Carina Friska Lingga
 */
public class SynchronizedMain {
     
    public static void main(String _args[]){
        Printer p = new SynchronizedPrinter(System.out, 500);
        User user1 = new User(p);
        User user2 = new User(p);
        User user3 = new User(p);
        
        user1.workOn("0123456789");
        user2.workOn("abcdefghij");
        user3.workOn("!@#$%^&*()_+");
        
    }
    
}
