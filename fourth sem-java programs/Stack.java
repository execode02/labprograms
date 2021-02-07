/*1b.Write a Java program to implement the Stack using arrays. Write Push(), Pop(), and 
Display() methods to demonstrate its working.*/

package lab1b;
import java.util.Scanner;

public class Stack{
	final int max=100;
	int s[]=new int[max];
	int top=-1;
	void push(int ele) {
		if(top>max-1)
			System.out.println("Stack Overflow");
		else
			s[++top]=ele;
	}
	void pop() {
		int z=0;
		if(top==-1)
			System.out.println("Stack Underflow");
		else
			z=s[top--];
		System.out.println("Popped element is " + z);
	}
	void display() {
		if(top==-1)
			System.out.println("Stack is empty");
		else
			for(int i=top;i>-1;i--)
				System.out.println(s[i]);
	}
	public static void main(String[] args) {
		int q=1;
		Stack m=new Stack();
		System.out.println("Program to perform stack operations");
		Scanner sc= new Scanner(System.in);
		while(q!=0) {
			System.out.println("Enter\n1.push\n2.pop\n3.display\n4.exit");
			System.out.println("Enter your choice: ");
			int ch=sc.nextInt();
			switch(ch) {
			case 1:
				System.out.println("Enter the element to be pushed: ");
				int ele=sc.nextInt();
				m.push(ele);
				break;
			case 2:
				m.pop();
				break;
			case 3:
				m.display();
				break;
			case 4:
				System.out.println("Exited");
				q=0;
			}
		}
		sc.close();	
	}
}