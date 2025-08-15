import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main_1757 {
    static int n, m;
    static int[] prefix, dp;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken()); m = Integer.parseInt(st.nextToken());
        dp = new int[n+1]; prefix = new int[n+1];
        for(int i = 1; i <= n; i++){
            prefix[i] = prefix[i-1] + Integer.parseInt(br.readLine());
        }
        for(int i = 1; i <= n; i++){
            dp[i] = dp[i-1];
            for(int j = 1; j <= m; j++){
                if(dp[i-j*2+1] >= 0) dp[i] = Math.max(dp[i], dp[i-j*2+1] + prefix[i-j] - prefix[i-j*2+1]);
            }
        }
        System.out.println(Arrays.toString(dp));
        System.out.println(dp[n]);
    }
}
