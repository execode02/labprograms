/*3b.Write a Java program that implements a multi-thread application that has three threads.
First thread generates a random integer for every 1 second; second thread computes the
square of the number and prints; third thread will print the value of cube of the number.*/

package lab3b;		
import java.util.*;
class Square implements Runnable{
	public int x;
	public Square(int x){
		this.x=x;
	}
	public void run(){
		System.out.println("Second thread generated square of "+x+" = "+x*x);
	}
}
class Cube implements Runnable{
	public int x;
	public Cube(int y){
		this.x=y;// constructor of the third thread
	}
	public void run(){
		System.out.println("Third thread generated cube of "+x+" = "+x*x*x);
	}
}
class First extends Thread{
	public void run(){
		int n=0;
		Random r=new Random();
		try{
			for(int i=0;i<10;i++){
				System.out.println("-------------"+(i+1)+" number generated--------------");
				n=r.nextInt(100);
				System.out.println("First Thread Generated random number = "+n);
				//Thread.sleep(1000);
				Thread t2=new Thread(new Square(n));//second thread
				t2.start();
				Thread t3=new Thread(new Cube(n));//third thread
				t3.start();
				Thread.sleep(1000);
				//System.out.println("-------------"+(i+1)+" number generated--------------");
			}
		}
		catch(Exception e){
			System.out.println(e.getMessage());
		}
	}
}
public class MultiThreadApplication {
	public static void main(String[] args) {
		First d=new First();
		d.start();
	}
}