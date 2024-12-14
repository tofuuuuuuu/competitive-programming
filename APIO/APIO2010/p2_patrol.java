import java.io.*;
import java.util.*;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Administrator
 */
public class patrol {
    static ArrayList<edge>[] adj;
    static edge[] prevEdge;
    static int[] weight, dist;
    static int maxDist = 0;
    static int maxNode = 0;
    public static void main(String[] args) throws IOException {
        //BufferedReader br = new BufferedReader(new FileReader("filename.in")); 
        //PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("filename.out")));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
        
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        adj = new ArrayList[n];
        prevEdge = new edge[n];
        weight = new int[n];
        dist = new int[n];
        for(int i = 0; i < n; i++) {
            adj[i] = new ArrayList<>();
        }
        for(int i = 0; i < n-1; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken())-1;
            int b = Integer.parseInt(st.nextToken())-1;
            adj[a].add(new edge(b, i)); 
            adj[b].add(new edge(a, i));
            weight[i] = 1;
        }
        
        int ans = 2*(n-1);
        if(k == 1) {
            dfs(0, 0, 0);
            maxDist = 0;
            dfs(maxNode, maxNode, 0);
            ans = ans - maxDist + 1;
        }
        else {
            dfs(0, 0, 0);
            maxDist = 0;
            dfs2(maxNode, maxNode, 0);
            int curNode = maxNode;
            while(prevEdge[curNode] != null) {
                weight[prevEdge[curNode].id] = -1;
                curNode = prevEdge[curNode].v;
            }
            ans = ans - maxDist + 1;
            
            maxDist = 0;
            dfs3(0, 0);
            ans = ans - maxDist + 1;
        }
        out.println(ans);
        br.close();
        out.close();
    }
    
    public static void dfs(int v, int prev, int curDist) {
        if(curDist > maxDist) {
            maxDist = curDist;
            maxNode = v;
        }
        for(edge i : adj[v]) {
            if(i.v == prev) continue;
            dfs(i.v, v, curDist+1);
        }
    }
    
    public static void dfs2(int v, int prev, int curDist) {
        if(curDist > maxDist) {
            maxDist = curDist;
            maxNode = v;
        }
        for(edge i : adj[v]) {
            if(i.v == prev) continue;
            prevEdge[i.v] = new edge(v, i.id);
            dfs2(i.v, v, curDist+1);
        }
    }
    
    public static void dfs3(int v, int prev) {
        for(edge i : adj[v]) {
            if(i.v == prev) continue;
            dfs3(i.v, v);
            maxDist = Math.max(maxDist, dist[v] + dist[i.v] + weight[i.id]);
            dist[v] = Math.max(dist[v], dist[i.v] + weight[i.id]);
        }
    }
    
    static class edge {
        int v; int id; 
        public edge(int vertex, int index) {
            v = vertex; id = index; 
        }
    }
}