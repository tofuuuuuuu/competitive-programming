import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Stack;
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
public class balancedCycles {
    static int n;
    static ArrayList<edge>[] adj;
    static boolean[] removed;
    static int[] size;
    static HashMap<Integer, Integer> freq = new HashMap<>();
    static ArrayList<Integer> ds = new ArrayList<>();
    static long ans = 0;
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());;
        n = Integer.parseInt(st.nextToken());
        adj = new ArrayList[n];
        removed = new boolean[n];
        size = new int[n];
        for(int i = 0; i < n; i++) {
            adj[i] = new ArrayList<>();
        }
        for(int i = 0; i < n-1; i++) {
            String[] s = br.readLine().split(" ");
            int a = Integer.parseInt(s[0])-1; int b = Integer.parseInt(s[1])-1;
            int c = 1; if(s[2].charAt(0) == 'b') c = -1;
            
            adj[a].add(new edge(b, c)); adj[b].add(new edge(a, c));
        }
        
        fun(0);
        System.out.println(ans - n + 1);
    }
    
    static class edge {
        int v; int c;
        public edge(int vertex, int colour) {
            v = vertex; c = colour;
        }
    }
    
    public static void findSize(int v, int prev) {
        size[v] = 1;
        for(edge i : adj[v]) {
            if(i.v == prev || removed[i.v]) continue; 
            findSize(i.v, v);
            size[v] += size[i.v];
        }
    }
    
    public static int findCentroid(int v, int prev, int nodeAmount) {
        for(edge i : adj[v]) {
            if(i.v == prev || removed[i.v]) continue;
            
            if(2*size[i.v] >= nodeAmount) {
                return findCentroid(i.v, v, nodeAmount);
            }
        }
        return v;
    }
    
    public static void dfs(int v, int prev, int curDist) {
        for(edge e : adj[v]) {
            if(e.v == prev || removed[e.v]) continue;

            int d = curDist + e.c; ds.add(d);
            if(freq.containsKey(1-d)) ans += freq.get(1-d); 
            if(freq.containsKey(-1-d)) ans += freq.get(-1-d);
            dfs(e.v, v, d);
        }
    }
    
    public static void fun(int v) {
        findSize(v, -1);
        int centroid = findCentroid(v, -1, size[v]); removed[centroid] = true;
        
        freq = new HashMap<>();
        ds = new ArrayList<>();
        freq.put(0, 1);
        for(edge i : adj[centroid]) {
            if(removed[i.v]) continue;
            ds.add(i.c); 
            if(freq.containsKey(1-i.c)) ans += freq.get(1-i.c); 
            if(freq.containsKey(-1-i.c)) ans += freq.get(-1-i.c);
            dfs(i.v, centroid, i.c);
            
            for(int n : ds) {
                if(freq.containsKey(n)) {
                    freq.replace(n, freq.get(n) + 1);
                }
                else {
                    freq.put(n, 1);
                }
            }
            ds.clear();
        }
        
        for(edge i: adj[centroid]) {
            if(!removed[i.v]) fun(i.v);
        }
    }
}