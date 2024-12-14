import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
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
public class goodInfluencers {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static ArrayList<Integer>[] adj;
    public static String want;
    public static long[] cost;
    public static long[][][] dp;
    
    public static void main(String[] args) throws IOException {
        int n = readInt();
        adj = new ArrayList[n];
        for(int i = 0; i < n; i++) {
            adj[i] = new ArrayList<>();
        }
        for(int i = 0; i < n-1; i++) {
            int a = readInt()-1; int b = readInt()-1;
            adj[a].add(b); adj[b].add(a);
        }
        
        cost = new long[n];
        want = readLine();
        for(int i = 0; i < n; i++) {
            cost[i] = readInt();
        }
        dp = new long[n][2][2];
        for(int i = 0; i < n; i++) {
            dp[i][0][0] = Integer.MAX_VALUE; dp[i][0][1] = Integer.MAX_VALUE;
            dp[i][1][0] = Integer.MAX_VALUE; dp[i][1][1] = Integer.MAX_VALUE;
        }
        
        recurse(0, 0);
        System.out.println(Math.min(dp[0][1][0], dp[0][1][1]));
    }
    
    public static void recurse(int v, int prev) {
        dp[v][0][0] = 0; dp[v][0][1] = cost[v];
        if(want.charAt(v) == 'Y') {
            dp[v][1][0] = 0; dp[v][1][1] = cost[v];
        }
        
        for(int i : adj[v]) {
            if(i == prev) continue;
            long[][] temp = new long[2][2];
            temp[0][0] = Integer.MAX_VALUE; temp[0][1] = Integer.MAX_VALUE;
            temp[1][0] = Integer.MAX_VALUE; temp[1][1] = Integer.MAX_VALUE;
            
            recurse(i, v); 
            for(int vWrite = 0; vWrite < 2; vWrite++) {
                for(int vPush = 0; vPush < 2; vPush++) {
                    for(int iWrite = 0; iWrite < 2; iWrite++) {
                        for(int iPush = 0; iPush < 2; iPush++) {
                            if(iWrite == 0 && vPush == 0) continue;
                            temp[vWrite | (iPush & iWrite)][vPush] = Math.min(temp[vWrite | (iPush & iWrite)][vPush], 
                                                                   dp[v][vWrite][vPush]+dp[i][iWrite][iPush]);
                        }
                    }
                }
            }
            
            dp[v][0][0] = temp[0][0]; dp[v][0][1] = temp[0][1];
            dp[v][1][0] = temp[1][0]; dp[v][1][1] = temp[1][1];
        }
    }
    
    static String next() throws IOException {
            while (st == null || !st.hasMoreTokens())
                    st = new StringTokenizer(br.readLine().trim());
            return st.nextToken();
    }

    static int readInt() throws IOException {
            return Integer.parseInt(next());
    }

    static String readLine() throws IOException {
            return br.readLine().trim();
    }
}