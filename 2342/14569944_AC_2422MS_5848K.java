//poj - 2531

import java.util.Scanner;

public class Main {

//    private static int[] happy = new int[6005];
    private static int[] father = new int[6005];
    private static int[][] dp = new int[6005][2];
    private static boolean[] bl = new boolean[60005];
    private static int N;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
//        while (scanner.hasNext()) {
        N = scanner.nextInt();
        for (int i = 1; i <= N; i++) {
            dp[i][1] = scanner.nextInt();
        }
        int l;
        int k;
        while ((l = scanner.nextInt()) != 0 && (k = scanner.nextInt()) != 0) {
            father[l] = k;
        }
        int root = 1;
        while (father[root] != 0) {
            root = father[root];
        }
//        System.out.println("root="+root);
        dfs(root);
        System.out.println(Math.max(dp[root][0], dp[root][1]));

    }

    private static void dfs(int node) {
        bl[node] = true;
        for (int i = 1; i <= N; i++) {
            if (!bl[i] && father[i] == node) {
                dfs(i);
                dp[node][1] += dp[i][0];
                dp[node][0] += Math.max(dp[i][0], dp[i][1]);
            }
        }
    }
//    }


}

