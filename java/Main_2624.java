import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main_2624 {
    static int t, k;
    static int[][] dp;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        t = Integer.parseInt(br.readLine()); k = Integer.parseInt(br.readLine());
        dp = new int[k+1][t+1];
        dp[0][0] = 1;
        for(int i = 0; i < k; i++){
            st = new StringTokenizer(br.readLine());
            int p = Integer.parseInt(st.nextToken()), n = Integer.parseInt(st.nextToken());
            for(int j = t; j >= 0; j--){
                if(dp[i][j] != 0) continue;
                for(int m = 0; m < n; m++){
                    if(j+m*p > t) break;
                    dp[i+1][j+m*p] += dp[i][j];
                }
            }
        }
        System.out.println(dp[k][t]);
    }
}
