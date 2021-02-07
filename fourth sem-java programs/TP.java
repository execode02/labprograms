/*10 b Write Java program to implement Travelling Sales Person problem using Dynamic programming*/

package lab10b;
import java.util.Scanner;

class TSP{
	int n;
	int a[][]=new int[10][10];
	int cost=0;
	int visited[]=new int[10];
	TSP(){
		Scanner sc=new Scanner(System.in);
		System.out.println(" Enter the number of cities");
		n= sc.nextInt();
		System.out.println("Enter the cost Matrix");
		for(int i=0;i<n;i++){
			System.out.println("Enter the elements of row:"+(i+1));
			for(int j=0;j<n;j++){
				a[i][j]= sc.nextInt();
			}
			visited[i]=0;
		}
		System.out.println(" The cost list ");
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				System.out.print(a[i][j]+"\t");
			}
			System.out.println("\n");
		}
		sc.close();
	}
	void mincost(int city){
		int ncity;
		visited[city]=1;
		System.out.print((city+1)+"-->");
		ncity=least(city);
		if(ncity==999){
			ncity=0;
			System.out.print((ncity+1));
			cost+=a[city][ncity];
			return;
		}
		mincost(ncity);
	}
	int least(int c){
		int nc=999, min=999;
		for(int i=0;i<n;i++){
			if(a[c][i]!=0 && visited[i]==0)
				if(a[c][i]<min){
					min=a[c][i];
					nc=i;
				}
		}
		if(min!=999)
			cost+=min;
		return nc;
	}		
}
public class TP{
	public static void main(String[] args) {
		TSP t=new TSP();
		System.out.println("TSP tour for the given cities is:");
		t.mincost(0);
		System.out.println("\n Minimum cost=:"+t.cost);
	}
}