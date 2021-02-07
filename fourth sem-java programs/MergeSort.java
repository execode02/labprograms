/*5.Sort a given set of n integer elements using Merge Sort method and compute its time
complexity. Run the program for varied values of n> 5000, and record the time taken to sort.
Plot a graph of the time taken versus non graph sheet. The elements can be read from a file or
can be generated using the random number generator. Demonstrate using Java how the divide and-
conquer method works along with its time complexity analysis: worst case, average case and best case.*/

package lab5;
import java.util.*;
public class MergeSort {
	public static void MS(int []a,int n){
		int p=0,q=0;
		int []b=new int[100],c=new int[100];
		if(n>1){
			for(int i=0;i<=((n/2)-1);i++){
				b[p]=a[i];
				p++;
			}
			for(int i=(n/2);i<=n-1;i++){
				c[q]=a[i];
				q++;
			}
			MS(b,p);
			MS(c,q);
			merge(b,c,a,p,q);
		}
	}
	public static void merge(int []b,int[]c, int []a,int p,int q){
		int i=0,j=0,k=0;
		while(i<p && j<q){
			if(b[i]<=c[j])
				a[k]=b[i++];
			else 
				a[k]=c[j++];
			k++;
		}
		if(i==p){
			for(int x=j;x<=q-1;x++)
				a[k++]=c[x];
		}
		else {
			for(int x=i;x<=p-1;x++)
				a[k++]=b[x];
			
		}
	}
	public static Scanner sc;
	public static void main(String[] args) {
		int []a=new int[9000];
		sc=new Scanner(System.in);
		System.out.println("enter the no of elements");
		int n=sc.nextInt();
		System.out.println("the elements before sorting");
		for(int i=0;i<n;i++){
			Random r=new Random();
			a[i]=r.nextInt(100);
			System.out.print(a[i]+"\n");
			}
		long start=System.nanoTime();
		MS(a,n);
		long stop=System.nanoTime();
		long elapsetime=(stop-start);
		System.out.println("\n\nthe elements after sorting in ascending order");
		for(int i=0;i<n;i++)
			System.out.print(a[i]+"\t");
		System.out.println("\n\n\nTime taken to sort "+n+" elements is "+elapsetime+"ns");
	}
}