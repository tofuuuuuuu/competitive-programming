import java.io.*;
import java.util.*;
import java.math.BigInteger;

public class main {
    static long MOD = 1000000007;
    static int n;
    static BigInteger big_n;
    static BigInteger z;
    static BigInteger ZEROO = BigInteger.ZERO;
    static BigInteger ONEE = BigInteger.ONE;
    static BigInteger TWOO = BigInteger.ONE.add(BigInteger.ONE);
    static BigInteger MODD = new BigInteger("1000000007");
    static long[][] a = new long[11][11];
    static long[][] cur = new long[11][11];
    static long[][] tmp = new long[11][11];

    public static void base_mult() {
        long[][] tmp = new long[n+1][n+1];
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                for(int k = 1; k <= n; k++) {
                    tmp[i][j] = (tmp[i][j] + a[i][k] * a[k][j]) % MOD;
                }
            }
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                a[i][j] = tmp[i][j];
            }
        }
    }

    public static void cur_mult() {
        long[][] tmp = new long[n+1][n+1];
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                for(int k = 1; k <= n; k++) {
                    tmp[i][j] = (tmp[i][j] + cur[i][k] * a[k][j]) % MOD;
                }
            }
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                cur[i][j] = tmp[i][j];
            }
        }
    }

    public static void main(String[] args) throws IOException {
        //BufferedReader br = new BufferedReader(new FileReader("filename.in"));
        //PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("filename.out")));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        
        n = Integer.parseInt(st.nextToken());
        big_n = BigInteger.valueOf(n); 
        z = new BigInteger(st.nextToken());

        BigInteger period = ONEE;
        for(int i = 1; i <= n; i++) {
            period = period.multiply(MODD.pow(i).subtract(ONEE));
        }

        z = z.mod(period);
        
        st = new StringTokenizer(br.readLine());
        for(int i = 1; i <= n; i++) {
            a[1][i] = Long.parseLong(st.nextToken());
        }
        for(int i = 2; i <= n; i++) {
            a[i][i-1] = 1;
        }
        for(int i = 1; i <= n; i++) {
            cur[i][i] = 1;
        }

        if(z.compareTo(big_n) <= 0) {
            System.out.println(1);
            return;
        }
        
        z = z.subtract(big_n);
        while(z.compareTo(ZEROO) == 1) {
            if(z.and(ONEE).equals(ONEE)) {
                cur_mult();
            }

            base_mult();
            z = z.shiftRight(1);
        }

        long ret = 0;
        for(int i = 1; i <= n; i++) {
            ret = (ret + cur[1][i]) % MOD;
        }
        
        System.out.println(ret);

        br.close();
        out.close();
    }
}