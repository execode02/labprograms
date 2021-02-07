//9. Find Minimum Cost Spanning Tree of a given connected undirected graph using Prim's algorithm

package lab9;
import java.util.Scanner;

class Prims {
	void spann_prims(int w[][],int n,int s)
	{		
		int min,u=0,v=0,i,j,k=0,sum=0,flag=0;
		int sol[]=new int[10];
		for( i=1;i<=n;i++)
			sol[i]=0;
		sol[s]=1;
		k=1;
		while(k<=n-1){
			min=999;
			for(i=1;i<=n;i++)
				if(sol[i]==1)
					for(j=1;j<=n;j++)
						if(i!=j && min>w[i][j] && sol[j]==0){
							min=w[i][j];
							u=i;
						    v=j;
					      }		
			sol[v]=1;
			sum=sum+min;
			k++;
			System.out.println("Edge :"+u+"-->"+v+"="+min);
		}
		for(i=1;i<=n;i++)
			if(sol[u]==0)
				flag=1;
		if(flag==1)
			System.out.println("No spanning tree");
		else
			System.out.println("The cost of minimum spanning tree is ="+sum);
	}
}

public class PrimsDemo {

	public static void main(String[] args) {
		int n, s;
		int w[][]=new int[10][10];
		Prims p = new Prims();
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter the number of vertices of graph : ");
		n = sc.nextInt();
		System.out.println("Enter the weighted graph: ");
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				w[i][j]=sc.nextInt();
		System.out.print("Enter the source vertex : ");
		s = sc.nextInt();
		p.spann_prims(w,n,s);
		sc.close();
	}
}