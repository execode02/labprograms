/*6a.Implement in Java, the 0/1 Knapsack problem using  Dynamic Programming method */

package lab6a;
import java.util.Scanner;

public class Knap{
	public void solve(int[] wt, int[] val, int W, int N){
		int i,j;
		int[][] sol = new int[N + 1][W + 1];
		for( i = 0; i<= N; i++){
			for( j = 0; j <= W; j++){
				if(i==0||j==0)
					sol[i][j]=0;
				else if(wt[i]>j)
					sol[i][j]=sol[i-1][j];
				else
					sol[i][j]=Math.max((sol[i-1][j]), (sol[i - 1][j - wt[i]] + val[i]));
			}
		}
		System.out.println("The optimal solutionis"+sol[N][W]);
		int[] selected = new int[N + 1];
		for(i=0;i<N+1;i++)
			selected[i]=0;
		i=N;
		j=W;
		while(i>0&&j>0){
			if(sol[i][j] !=sol[i-1][j]){
				selected[i] = 1;
				j = j - wt[i];
			}
		i--;
		}
		System.out.println("\nItems selected : ");
		for( i = 1; i< N + 1; i++)
			if(selected[i] == 1)
				System.out.print(i +" ");
		System.out.println();
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Knap ks = new Knap();
		System.out.println("Enter number of elements ");
		int n = sc.nextInt();
		int[] wt = new int[n + 1];
		int[] val = new int[n + 1];
		System.out.println("\nEnter weight for "+ n +"elements");
		for(int i = 1; i<= n; i++)
			wt[i] = sc.nextInt();
		System.out.println("\nEnter value for "+ n +"elements");
		for(int i = 1; i<= n; i++)
			val[i] = sc.nextInt();
		System.out.println("\nEnter knapsack weight ");
		int W = sc.nextInt();
		ks.solve(wt, val, W, n);
		sc.close();
	}
}