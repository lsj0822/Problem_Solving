import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main_15487 {
    static int n;
    static int[] arr;
    static int[][] dp;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        n = Integer.parseInt(br.readLine());
        arr = new int[n]; dp = new int[n][4];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            Arrays.fill(dp[i], Integer.MIN_VALUE);
            arr[i] = Integer.parseInt(st.nextToken());
            if(i == 0) dp[i][0] = -arr[i];
            else dp[i][0] = Math.max(dp[i-1][0], -arr[i]);
        }
        dp[1][1] = -arr[0] + arr[1];
        dp[2][1] = Math.max(dp[1][1], dp[1][0] + arr[2]);
        dp[2][2] = -arr[0] + arr[1] - arr[2];
        for(int i = 3; i < n; i++){
            for(int j = 1; j < 4; j++){
                if(j % 2 == 0) dp[i][j] = Math.max(dp[i-1][j], dp[i-1][j-1] - arr[i]);
                else dp[i][j] = Math.max(dp[i-1][j], dp[i-1][j-1] + arr[i]);
            }
        }
        System.out.println(dp[n-1][3]);
    }
}
