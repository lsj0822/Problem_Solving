import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main_11066 {
    static int t, n;
    static int[] prefix;
    static int[][] dp;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        t = Integer.parseInt(br.readLine());
        while(t-->0){
            n = Integer.parseInt(br.readLine());
            dp = new int[n+1][n+1]; prefix = new int[n+1];
            for(int i = 1; i <= n; i++) Arrays.fill(dp[i], Integer.MAX_VALUE);
            st = new StringTokenizer(br.readLine());
            for(int i = 1; i <= n; i++){
                prefix[i] = prefix[i-1] + Integer.parseInt(st.nextToken());
                dp[i][i] = 0;
            }
            for(int i = 1; i < n; i++){
                for(int j = 1; i + j <= n; j++){
                    for(int k = j; k < i+j; k++) dp[j][i+j] = Math.min(dp[j][i+j], dp[j][k] + dp[k+1][j+i] + prefix[i+j] - prefix[j-1]);
                }
            }
            System.out.println(dp[1][n]);
        }
    }
}
