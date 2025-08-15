import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main_11049 {
    static int n;
    static Matrix[] arr;
    static int[][] dp;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        n = Integer.parseInt(br.readLine());
        arr = new Matrix[n]; dp = new int[n][n];
        for(int i = 0; i < n; i++){
            st = new StringTokenizer(br.readLine());
            Arrays.fill(dp[i], Integer.MAX_VALUE);
            dp[i][i] = 0;
            int r = Integer.parseInt(st.nextToken()), c = Integer.parseInt(st.nextToken());
            arr[i] = new Matrix(r, c);
        }
        for(int d = 1; d <= n-1; d++){
            for(int s = 0; s+d < n; s++){
                for(int k = s; k < s+d; k++){
                    dp[s][s+d] = Math.min(dp[s][s+d], dp[s][k] + dp[k+1][s+d] + arr[s].r * arr[k].c * arr[s+d].c);
                }
            }
        }
        System.out.println(dp[0][n-1]);
    }

    static class Matrix{
        int r, c;
        public Matrix(int r, int c){
            this.r = r; this.c = c;
        }
    }
}
