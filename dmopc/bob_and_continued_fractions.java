import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
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
public class bobAndContinuedFractions {
    static long mod = 1000000007;
    static matrix[] seg = new matrix[12000007];
    public static void main(String[] args) throws IOException {
        //BufferedReader br = new BufferedReader(new FileReader("filename.in")); 
        //PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("filename.out")));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
        
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int q = Integer.parseInt(st.nextToken());
        long[] a = new long[n];
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++) {
            a[i] = Long.parseLong(st.nextToken());
        }
        construct(0, 0, n-1, a);
        
        for(int cases = 0; cases < q; cases++) {
            st = new StringTokenizer(br.readLine());
            int l = Integer.parseInt(st.nextToken())-1;
            int r = Integer.parseInt(st.nextToken())-1;
            if(l == r) {
                out.println(a[l] + " 1");
                continue;
            }
            
            matrix m = product(0, 0, n-1, l, r-1);
            long num = m.a*a[r] + m.b;
            long denom = m.c*a[r] + m.d;
            num %= mod; 
            denom %= mod;
            out.println(num + " " + denom);
        }
        br.close();
        out.close();
    }
    
    public static class matrix {
        long a; long b; long c; long d;
        
        public matrix(long a00, long a01, long a10, long a11) {
            a = a00; b = a01; c = a10; d = a11;
        }
    }
    
    public static matrix mult(matrix a, matrix b) {
        long na = a.a*b.a + a.b*b.c;
        long nb = a.a*b.b + a.b*b.d;
        long nc = a.c*b.a + a.d*b.c;;
        long nd = a.c*b.b + a.d*b.d;;
        return new matrix(na%mod, nb%mod, nc%mod, nd%mod);
    }
    
    static void construct(int cur, int l, int r, long[] a) {
        if(l == r) {
            seg[cur] = new matrix(a[l], 1, 1, 0);
            return;
        }
        
        int m = (l+r)/2;
        construct(cur*2 + 1, l, m, a); 
        construct(cur*2 + 2, m+1, r, a);
        seg[cur] = mult(seg[cur*2 + 1], seg[cur*2 + 2]);
    }
    
    static matrix product(int cur, int l, int r, int ql, int qr) {
        if(ql <= l && r <= qr) {
            return seg[cur];
        }
        
        if(r < ql || qr < l) {
            return new matrix(1, 0, 0, 1);
        }
        
        int m = (l+r)/2;
        matrix a = product(cur*2+1, l, m, ql, qr);
        matrix b = product(cur*2+2, m+1, r, ql, qr);
        return mult(a, b);
    }
}