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
public class cheapestOperationEver {
    public static void main(String[] args) throws IOException {
        //BufferedReader br = new BufferedReader(new FileReader("filename.in")); 
        //PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("filename.out")));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
        
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        long h = Integer.parseInt(st.nextToken());
        long[] p = new long[n+1];
        st = new StringTokenizer(br.readLine());
        for(int i = 1; i <= n; i++) {
            p[i] = Integer.parseInt(st.nextToken());
        }
        for(int i = 2; i <= n; i++) {
            p[i] -= p[1];
        }
        p[1] = 0;
        
        long[] dp = new long[n+1];
        ArrayDeque<line> q = new ArrayDeque<>();
        dp[0] = 0;
        q.add(new line(-2*p[1], p[1]*2));
        for(int i = 1; i < n; i++) {
            while(q.size () > 1) {
                line first = q.pollFirst();
                line second = q.peekFirst();
                if(eval(first, p[i]) < eval(second, p[i])) {
                    q.offerFirst(first);
                    break;
                }
            }
            
            dp[i] = p[i]*p[i] + h + eval(q.peekFirst(), p[i]);
            line cur = new line(-(long)2*p[i+1], dp[i] + p[i+1]*p[i+1]);
            while(q.size() > 1) {
                line last = q.pollLast();
                line secondLast = q.peekLast();
                if(inter(cur, secondLast) > inter(last, secondLast)) {
                    q.offerLast(last);
                    break;
                }
            }
            q.offerLast(cur);
        }
        while(q.size () > 1) {
            line first = q.pollFirst();
            line second = q.peekFirst();
            if(eval(first, p[n]) < eval(second, p[n])) {
                q.offerFirst(first);
                break;
            }
        }
        dp[n] = p[n]*p[n] + h + eval(q.peekFirst(), p[n]);
        
        out.println(dp[n]);
        br.close();
        out.close();
    }
    
    static class line{
        long m; long b;
        public line(long slope, long yint) {
            m = slope; b = yint;
        }
    }
    
    static long eval(line a, long x) {
        return a.m*x + a.b;
    }
    
    static double inter(line a, line b) {
        return ((double)b.b - a.b)/((double)a.m - b.m);
    }
}