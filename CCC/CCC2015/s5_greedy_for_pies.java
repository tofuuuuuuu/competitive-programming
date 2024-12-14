import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Administrator
 */
public class greedyForPies {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static int n;
    public static int m;
    public static int[] a; 
    public static int[] b;
    public static int[][][][] dp;
    
    public static void main(String[] args) throws IOException {
        n = readInt();
        a = new int[n+1];
        for(int i = 1; i <= n; i++) {
            a[i] = readInt();
        }
        m = readInt();
        b = new int[m+1];
        for(int i = 1; i <= m; i++) {
            b[i] = readInt();
        }
        Arrays.sort(b);
        dp = new int[3005][2][105][105];
        for(int i = 0; i < 3005; i++) {
            for(int j = 0; j < 2; j++) {
                for(int k = 0; k < 105; k++) {
                    for(int l = 0; l < 105; l++) {
                        dp[i][j][k][l] = -1;
                    }
                }
            }
        }
        
        System.out.println(sugar(1, 1, 1, m));
    }
    
    public static int sugar(int i, int can, int l, int r) {
        if(dp[i][can][l][r] != -1) return dp[i][can][l][r];
        
        int ans = 0;
        if(i <= n) {
            ans = Math.max(ans, sugar(i+1, 1, l, r));
            if(can == 1) ans = Math.max(ans, a[i] + sugar(i+1, 0, l, r));
        }
        if(l <= r) {
            ans = Math.max(ans, sugar(i, 1, l+1, r));
            if(can == 1) ans = Math.max(ans, b[r] + sugar(i, 0, l, r-1));
        }
        dp[i][can][l][r] = ans;
        return ans;
    }
    
    static String next() throws IOException {
            while (st == null || !st.hasMoreTokens())
                    st = new StringTokenizer(br.readLine().trim());
            return st.nextToken();
    }

    static int readInt() throws IOException {
            return Integer.parseInt(next());
    }
}