/*7.From a given vertex in a weighted connected graph, find shortest paths to other vertices using
Dijkstra's algorithm. Write the program in Java*/

package lab7;
import java.util.Scanner;

class Dijkstra {
	void shortest(int n,int src,int cost[][]){ 
		int i, j, u=0,min;
		int s[]=new int[10];
		int d[]=new int[10];
		for(i=1;i<=n;i++){
			s[i]=0;
			d[i]=cost[src][i];
		}
		s[src]=1;
		for(i=1;i<=n;i++){
			min=999;
			for(j=1;j<=n;j++){
				if(s[j]==0)
				if(d[j]<min){
					min=d[j];
					   u=j;
				   }			
		    }
			s[u]=1;
			for(int m=1;m<=n;m++){				
					if(d[m]>(d[u]+cost[u][m]) && s[m]==0)
						d[m]=d[u]+cost[u][m];
			}
	    }
		System.out.println("Shortest path");
		for(int k=1;k<=n;k++){
			System.out.print(src+"-->"+k+"="+d[k]+"\n");
			
		}
    }	

}

public class DijkstraMain {
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		Dijkstra d=new Dijkstra();
		int i,j,n,src;
		int a[][]=new int[10][10];
		System.out.print("Enter the number of vertice : ");
		n=sc.nextInt();
	            System.out.print("Enter the cost adjacency matrix\n(Enter 999 if there is no edge)\n ");
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++)
				a[i][j]=sc.nextInt();
		}
		System.out.print("Enter the source vertex : ");
		src=sc.nextInt();
		d.shortest(n,src,a);
		sc.close();
	}
}