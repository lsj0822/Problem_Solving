import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;

public class Main_32981 {
    static long[] arr = new long[(int)1e7 + 1];
    static final int MOD = (int)1e9 + 7;
    static HashMap<Integer, Long> hash = new HashMap<>();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        hash.put(0, 1L); hash.put(1, 5L);
        int q = Integer.parseInt(br.readLine());
        while(q-->0){
            int n = Integer.parseInt(br.readLine());
            if(n == 1) sb.append("5\n");
            else sb.append((dnq(n-1)*4)%MOD).append('\n');
        }
        System.out.println(sb.toString());
    }

    static long dnq(int n){
        if(hash.get(n) != null) return hash.get(n);
        long res;
        if(n % 2 == 1) res = 5 * (dnq(n/2) * dnq(n/2)) % MOD;
        else res = dnq(n/2) * dnq(n/2) % MOD;
        hash.put(n, res);
        return res;
    }
}
