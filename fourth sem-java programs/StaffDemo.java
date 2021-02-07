/*2a.Design a superclass called Staff with details as StaffId, Name, Phone, Salary. Extend this 
class by writing three subclasses namely Teaching (domain, publications), Technical
(skills), and Contract (period). Write a Java program to read and display at least 3 staff
objects of all three categories.*/

package lab2a;
import java.util.Scanner;
class Staff{
	String staffId,name;
	long phno;
	int salary;
	Scanner sc=new Scanner(System.in);
	void read() {
		System.out.println("Enter the Staff ID:");
		staffId=sc.next();
		System.out.println("Enter the name:");
		name=sc.next();
		System.out.println("Enter the phone number:");
		phno=sc.nextLong();
		System.out.println("Enter the salary:");
		salary=sc.nextInt();
	}
	void display() {
		System.out.println(staffId + "\t\t\t" + name + "\t\t\t" + phno + "\t\t\t" + salary + "\t\t\t");
	}
}
class Teaching extends Staff{
	String domain;
	int publication;
	void read() {
		super.read();
		System.out.println("Enter domain of the employee:");
		domain=sc.next();
		System.out.println("Enter the number of publications: ");
		publication=sc.nextInt();
	}
	void display() {
		super.display();
		System.out.println(domain + "\t\t\t" + publication + "\n");
	}
}
class Technical extends Staff{
	String skills[];
	void read() {
		super.read();
		System.out.println("Enter the skills of the employee seperated by comma:");
		skills=sc.next().split(",");
	}
	void dispaly() {
		super.display();
		for(int i=0;i<skills.length;i++)
			System.out.println(skills[i] + "\t");
		System.out.println("\n");
	}
}
class Contract extends Staff{
	int period;
	void read() {
		super.read();
		System.out.println("Enter the period of contract: ");
		period=sc.nextInt();
	}
	void display() {
		super.display();
		System.out.println(period + "\n");
	}
}
public class StaffDemo {
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter the value of n:");
		int n=sc.nextInt();
		Teaching T[]=new Teaching[n];
		Technical Te[]=new Technical[n];
		Contract C[]=new Contract[n];
		for(int i=0;i<n;i++){
			T[i]=new Teaching();
			Te[i]=new Technical();
			C[i]=new Contract();
		}
		for(int i=0;i<n;i++) {
			System.out.println("Enter the details of Teaching Staff " + (i+1));
			T[i].read();
		}
		for(int i=0;i<n;i++) {
			System.out.println("Enter the details of Teachnical Staff " + (i+1));
			Te[i].read();
		}
		for(int i=0;i<n;i++) {
			System.out.println("Enter the details of Contract Staff " + (i+1));
			C[i].read();
		}
		System.out.println("Details of teaching staff are:");
		System.out.println("STAFF ID\t\t\tNAME\t\t\tPHONE NO.\t\t\tSALARY\t\t\tDOMAIN\t\t\tNO. OF PUBLICATIONS");
		for(int i=0;i<n;i++) {
			T[i].display();
			System.out.println("\n");
		}
		System.out.println("Details of teachnical staff are:");
		System.out.println("STAFF ID\t\t\tNAME\t\t\tPHONE NO.\t\t\tSALARY\t\t\tSKILLS");
		for(int i=0;i<n;i++) {
			Te[i].display();
			System.out.println("\n");
		}
		System.out.println("Details of contract staff are:");
		System.out.println("STAFF ID\t\t\tNAME\t\t\tPHONE NO.\t\t\tSALARY\t\t\tCONTRACT PERIOD");
		for(int i=0;i<n;i++) {
			C[i].display();
			System.out.println("\n");
		}
		sc.close();
	}
}