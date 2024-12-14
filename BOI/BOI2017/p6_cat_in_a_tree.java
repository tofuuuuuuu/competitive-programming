import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
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
public class catInATree {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static int d;
    public static ArrayList<Integer>[] adj;
    public static int[] dp;
    public static int ans = 0;
    
    public static void main(String[] args) throws IOException {
        int n = readInt(); d = readInt();
        adj = new ArrayList[n];
        for(int i = 0; i < n; i++) {
            adj[i] = new ArrayList<>();
        }
        for(int i = 1; i < n; i++) {
            adj[readInt()].add(i);
        }
        
        dp = new int[n]; 
        recurse(0);
        System.out.println(ans);
    }
    
    public static void recurse(int v) {
        if(adj[v].isEmpty()) {
            dp[v] = 0; ans++; return;
        }
        
        ArrayList<Integer> a = new ArrayList<>();
        for(int u : adj[v]) {
            recurse(u); a.add(dp[u]+1);
        }
        
        Collections.sort(a);
        while(a.size() > 1 && a.get(0) + a.get(1) < d) {
            a.remove(a.get(0)); ans--;
        }
        if(!a.isEmpty()) dp[v] = a.get(0);
        if(dp[v] == d) {
            dp[v] = 0;
            ans++;
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
}