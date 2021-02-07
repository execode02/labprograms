/*3a.Write a Java program to read two integers a and b. Compute a/b and print, when b is not
zero. Raise an exception when b is equal to zero.*/
package lab3a;
import java.util.Scanner;
public class ExceptionDemo {
	public static void main(String[] args) {
		int a,b;
		Scanner sc=new Scanner(System.in);
		System.out.println("enter two numbers");
		a=sc.nextInt();
		b=sc.nextInt();
		try{
			int result=a/b;
			System.out.println("result is "+result);
		}
		catch(ArithmeticException e){
			System.out.println(e);
		}
		sc.close();
	}
}