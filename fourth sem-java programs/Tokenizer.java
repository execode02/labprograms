/*2b.Write a Java class called Customer to store their name and date_of_birth. The date_of_birth 
format should be dd/mm/yyyy. Write methods to read customer data as <name, 
dd/mm/yyyy> and display as <name, dd, mm, yyyy> using StringTokenizer class 
considering the delimiter character as “/”.*/

package lab2b;
import java.util.Scanner;
import java.util.StringTokenizer;
class Customer {
	String name;
	String date;
	public void read() {
		Scanner sc=new Scanner(System.in);
		name= sc.next();
		date=sc.next();
	}
	public void display() {
		System.out.print(name);
		String delims="/";
		StringTokenizer st=new StringTokenizer(date,delims);
		while(st.hasMoreElements()) {
			System.out.print("," + st.nextElement());
		}
		System.out.println();
	}
}
public class Tokenizer{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter the number of customers: ");
		int n=sc.nextInt();
		System.out.println("Enter the customer details as <name dd/mm/yyyy> :");
		Customer cus[]=new Customer[n];
		for(int i=0;i<n;i++) {
			cus[i]=new Customer();
			System.out.println("Enter the customer " + (i+1) + "details");
			cus[i].read();
		}
		System.out.println("The customer details in format <name, dd, mm, yyyy>:");
		for(int i=0;i<n;i++)
			cus[i].display();
		sc.close();
	}
}
