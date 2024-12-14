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
public class palembangBridges {
    static int k, n;
    static long loSum, hiSum;
    static PriorityQueue<Integer> loq, hiq;
    static BufferedReader br;
    static PrintWriter out;
    static StringTokenizer st;
    
    public static void main(String[] args) throws IOException {
        //BufferedReader br = new BufferedReader(new FileReader("filename.in")); 
        //PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("filename.out")));
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(new OutputStreamWriter(System.out));
      
        st = new StringTokenizer(br.readLine());
        k = Integer.parseInt(st.nextToken());
        n = Integer.parseInt(st.nextToken());
        
        if(k == 1) {
            case1();
        }
        else {
            case2();
        }
        br.close();
        out.close();
    }
    
    public static void case1() throws IOException {
        long ans = 0;
        long noCross = 0;
        ArrayList<Integer> arr = new ArrayList<>();
        for(int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            String a = st.nextToken();
            int A = Integer.parseInt(st.nextToken());
            String b = st.nextToken();
            int B = Integer.parseInt(st.nextToken());

            if(a.charAt(0) == b.charAt(0)) {
                ans += Math.abs(A - B);
                noCross++;
            }
            else {
                arr.add(A);
                arr.add(B);
            }
        }
        Collections.sort(arr);

        if(arr.size() > 0) {
            int x = arr.get(arr.size()/2);
            for(int i : arr) {
                ans += Math.abs(x - i);
            }
        }

        out.println(ans + n - noCross);
    }
    
    public static void case2() throws IOException {
        long ans = 0;
        long noCross = 0;
        ArrayList<Pair> arr = new ArrayList<>();
        for(int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            String a = st.nextToken();
            int A = Integer.parseInt(st.nextToken());
            String b = st.nextToken();
            int B = Integer.parseInt(st.nextToken());

            if(a.charAt(0) == b.charAt(0)) {
                ans += Math.abs(A - B);
                noCross++;
            }
            else {
                arr.add(new Pair(Math.min(A, B), Math.max(A, B)));
            }
        }
        Collections.sort(arr);
        
        if(arr.size() == 0) {
            out.println(ans + n - noCross);
            return;
        }
        
        int sz = arr.size();
        loq = new PriorityQueue<>(new Cmp());
        hiq = new PriorityQueue<>();
        loSum = 0;
        hiSum = 0;
        long[] pref = new long[sz];
        
        loq.offer(arr.get(0).x); hiq.offer(arr.get(0).y);
        loSum = arr.get(0).x; hiSum = arr.get(0).y;
        pref[0] = hiSum - loSum;
        for(int i = 1; i < sz; i++) {
            int x = arr.get(i).x; int y = arr.get(i).y;
            insert(x, y);
            pref[i] = hiSum - loSum;
        }
        
        long s = 0;
        loq = new PriorityQueue<>(new Cmp());
        hiq = new PriorityQueue<>();
        loSum = 0;
        hiSum = 0;
        
        loq.offer(arr.get(sz-1).x); hiq.offer(arr.get(sz-1).y);
        loSum = arr.get(sz-1).x; hiSum = arr.get(sz-1).y;
        s = hiSum - loSum + pref[sz - 2];
        for(int i = sz - 2; i > 0; i--) {
            int x = arr.get(i).x; int y = arr.get(i).y;
            insert(x, y);
            
            s = Math.min(s, hiSum - loSum + pref[i-1]);
        }
        
        out.println(ans + n - noCross + s);
    }
    
    public static void insert(int x, int y) {
        if(x > hiq.peek()) {
            int hiLowest = hiq.poll();
            loq.offer(hiLowest);
            hiq.offer(x);
            hiq.offer(y);
            loSum += hiLowest;
            hiSum += (x + y - hiLowest);
        }
        else if(y < loq.peek()) {
            int loHighest = loq.poll();
            hiq.offer(loHighest);
            loq.offer(x);
            loq.offer(y);
            loSum += (x + y - loHighest);
            hiSum += loHighest;
        }
        else {
            loq.offer(x);
            hiq.offer(y);
            loSum += x;
            hiSum += y;
        }
    }
    
    public static class Pair implements Comparable<Pair>{
        int x, y;
        public Pair(int first, int second) {
            x = first; y = second;
        }

        @Override
        public int compareTo(Pair o) {
            return Integer.compare(this.x + this.y, o.x + o.y);
        }
    }
    
    public static class Cmp implements Comparator<Integer> { 
        @Override
        public int compare(Integer o1, Integer o2) {
            return Integer.compare(o2, o1);
        }
    }
}