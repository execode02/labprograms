/*4.Sort a given set of n integer elements using Quick Sort method and compute its time
complexity. Run the program for varied values of n> 5000 and record the time taken to sort.
Plot a graph of the time taken versus non graph sheet. The elements can be read from a file or
can be generated using the random number generator. Demonstrate using Java how the divide and-
conquer method works along with its time complexity analysis: worst case, average case
and best case.*/
package lab4;
import java.util.*;
public class QuickSortFinal2{
	public static int partition (int[] a, int low,int high){
		int p,i,j,temp;
		p=a[low];
		i=low+1;
		j=high;
		while(low<high){
			while(a[i]<=p&&i<high)
				i++;
			while(a[j]>p)
				j--;
			if(i<j){
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
			else{
				temp=a[low];
				a[low]=a[j];
				a[j]=temp;
				return j;
			}
		}
		return j;
	}
	public void sort(int[] a,int low,int high){
		if(low<high){
			int s=partition(a,low,high);
			sort(a,low,s-1);
			sort(a,s+1,high);
		}
	}
	public static Scanner sc =new Scanner(System.in);
	public static void main(String[] args) {
		int[] a;
		int i;
		System.out.println("Enter the array size");
		int n=sc.nextInt();
		a= new int[100];
		Random generator=new Random();
		for( i=0;i<n;i++)
			a[i]=generator.nextInt(100);
		System.out.println("Array before sorting");
		for( i=0;i<n;i++)
			System.out.println(a[i]+" ");
		QuickSortFinal2 m=new QuickSortFinal2();
		long startTime=System.currentTimeMillis();
		for(i=0;i<1000;i++)
			for(int j=0;j<1000;j++)
				m.sort(a,0,n-1);
		long stopTime=System.currentTimeMillis();
		long elapseTime=(stopTime-startTime);
		System.out.println("Sorted array is");
		for(i=0;i<n;i++)
			System.out.println(a[i]);
		System.out.println("Time taken to sort array is:"+elapseTime+"milliseconds");
	}

}