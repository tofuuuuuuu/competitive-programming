import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
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
public class commando {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    
    public static void main(String[] args) throws IOException {
        int n = readInt();
        long a = readInt(); long b = readInt(); long c = readInt();
        long[] psa = new long[n+1];
        for(int i = 1; i <= n; i++) {
            long x = readInt();
            psa[i] = psa[i-1] + x;
        }
        
        long[] dp = new long[n+1];
        ArrayDeque<line> deq = new ArrayDeque<>();
        deq.add(new line(0, 0));
        dp[1] = a*psa[1]*psa[1] + b*psa[1] + c;
        deq.add(new line(-2*a*psa[1], a*psa[1]*psa[1] - b*psa[1] + dp[1]));
        for(int i = 2; i <= n; i++) {
            while(deq.size() > 1) {
                line first = deq.pollFirst();
                line second = deq.peekFirst();
                if(eval(first, psa[i]) > eval(second, psa[i])) {
                    deq.offerFirst(first);
                    break;
                }
            }
            
            dp[i] = eval(deq.peekFirst(), psa[i]) + a*psa[i]*psa[i] + b*psa[i] + c;
            line cur = new line(-2*a*psa[i], a*psa[i]*psa[i] - b*psa[i] + dp[i]);
            while(deq.size() > 1) {
                line last = deq.pollLast();
                line secondLast = deq.peekLast();
                if(inter(cur, last) > inter(last, secondLast)) {
                    deq.offerLast(last);
                    break;
                }
            }
            deq.offerLast(cur);
        }
        
        System.out.println(dp[n]);
    }
    
    public static long eval(line l, long x) {
        return l.m*x + l.b;
    }
    
    public static double inter(line a, line b) {
        return ((double)b.b - a.b)/(a.m - b.m);
    }
    
    static class line{
        long m; long b;
        public line(long slope, long yint) {
            m = slope; b = yint;
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