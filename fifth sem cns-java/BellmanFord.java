import java.util.Scanner;

public class BellmanFord {
    public static final int MAX = 999;
    private int n;
    private int[] d;

    public BellmanFord(int n) {
        this.n = n;
        d = new int[n + 1];
    }

    public void bellmanFordEvaluation(int src, int[][] m) {
        for (int node = 1; node <= n; node++)
            d[node] = MAX;
        d[src] = 0;

        for (int node = 1; node <= n; node++) {
            for (int sn = 1; sn <= n; sn++) {
                for (int dn = 1; dn <= n; dn++) {
                    if ((m[sn][dn] != MAX) && (d[dn] > m[sn][dn] + d[sn]))
                        d[dn] = m[sn][dn] + d[sn];
                }
            }
        }
        for (int node = 1; node <= n; node++) {
            for (int sn = 1; sn <= n; sn++) {
                for (int dn = 1; dn <= n; dn++) {

                    if ((m[sn][dn] != MAX) && (d[dn] > m[sn][dn] + d[sn]))
                        System.out.println("The graph contains negative edge cycle!");
                }
            }
        }
        for (int node = 1; node <= n; node++) {
            System.out.println("Distance from " + src + " to " + node + " is " + d[node]);
        }

    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n, sn, dn, src;
        System.out.println("Enter the number of vertices");
        n = sc.nextInt();
        int[][] m = new int[n + 1][n + 1];

        System.out.println("Enter the adjacency matrix:");
        for (sn = 1; sn <= n; sn++) {
            for (dn = 1; dn <= n; dn++) {
                m[sn][dn] = sc.nextInt();
                if (sn == dn) {
                    m[sn][dn] = 0;
                    continue;
                }
                if (m[sn][dn] == 0)
                    m[sn][dn] = MAX;
            }
        }
        System.out.println("Enter the source vertex:");
        src = sc.nextInt();
        BellmanFord bf = new BellmanFord(n);
        bf.bellmanFordEvaluation(src, m);
    }
}