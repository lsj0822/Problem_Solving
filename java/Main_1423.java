import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main_1423 {
    static int[] cha, pow;
    static long[] dp;
    static final int MIN = (int)-1e9;
    static int n, d;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        n = Integer.parseInt(br.readLine());
        cha = new int[n]; pow = new int[n];
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++) cha[i] = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++) pow[i] = Integer.parseInt(st.nextToken());
        d = Integer.parseInt(br.readLine());
        dp = new long[d+1];
        long initPow = 0L;
        for(int i = 0; i < n; i++) initPow += (long)cha[i] * pow[i];
        Arrays.fill(dp, initPow);
        for(int i = 0; i < n-1; i++){
            if(cha[i] == 0) continue;
            int move = Math.min(cha[i], d);
            while(move-->0){
                for(int day = d; day >= 0; day--){
                    for(int j = i+1; j < n; j++){
                        if(day-(j-i) >= 0) dp[day] = Math.max(dp[day], dp[day-(j-i)] + pow[j] - pow[i]);
                    }
                }
            }
        }
        System.out.println(dp[d]);
    }
}
