import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main_2169 {
    static int n, m, ans = Integer.MIN_VALUE;
    static int[][] arr, dp;
    static int[] dx = {1,0,0}, dy=  {0,-1,1};
    static boolean[][][] vst;
    static Queue<int[]> que = new LinkedList<>();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());  m = Integer.parseInt(st.nextToken());
        arr = new int[n+1][m+1]; dp = new int[n+1][m+2];
        for(int i = 1; i <= n; i++){
            st = new StringTokenizer(br.readLine());
            Arrays.fill(dp[i], -(int)1e9);
            for(int j = 1; j <= m; j++){
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        dp[1][1] = arr[1][1];
        for(int i = 2; i <= m; i++) dp[1][i] = dp[1][i-1] + arr[1][i];
        for(int i = 2; i <= n; i++){
            int[][] tmp = new int[m+2][2];
            tmp[0][0] = Integer.MIN_VALUE; tmp[m+1][1] = Integer.MIN_VALUE;
            for(int j = 1; j <= m; j++){
               tmp[j][0] = Math.max(dp[i-1][j]+arr[i][j], tmp[j-1][0]+arr[i][j]);
               tmp[m+1-j][1] = Math.max(dp[i-1][m+1-j]+arr[i][m+1-j], tmp[m+2-j][1]+arr[i][m+1-j]);
            }
            for(int j = 1; j <= m; j++) dp[i][j] = Math.max(tmp[j][0], tmp[j][1]);
        }
        for(int i = 1; i <= n; i++) System.out.println(Arrays.toString(dp[i]));
        System.out.println(dp[n][m]);
    }
}
