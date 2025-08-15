import java.util.HashMap;
import java.util.Scanner;

public class Main_11444 {
    static long n;
    static final int MOD = (int)1e9 + 7;
    static HashMap<Long, Long> hash = new HashMap<>();
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextLong();
        hash.put(0L, 1L); hash.put(1L, 1L); hash.put(2L, 2L);
        System.out.println(n==0?0:DNQ(n - 1));
    }

    private static long DNQ(long n) {
        if(hash.get(n) != null) return hash.get(n);
        long res, fibo1 = DNQ(n/2), fibo2 = DNQ((n/2)-1), fibo3 = DNQ((n/2)+1);
        if(n % 2 == 1) res = ((fibo1 * fibo2) % MOD + (fibo1 * fibo3) % MOD) % MOD;
        else res = ((fibo1 * fibo1) % MOD + (fibo2 * fibo3) % MOD) % MOD;
        hash.put(n, res);
        return res;
    }
}
