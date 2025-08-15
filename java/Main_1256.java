import java.util.Arrays;
import java.util.Scanner;

public class Main_1256 {
    static int n, m, k;
    static long[][] dp;
    static int[] pos;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt(); m = sc.nextInt(); k = sc.nextInt();
        dp = new long[m][n+1]; pos = new int[n+1];
        for(int i = 0; i <= n; i++) dp[0][i] = i+1;
        for(int i = 1; i < m; i++){
            for(int j = 0; j <= n; j++){
                dp[i][j] = dp[i-1][j];
                if(j != 0) dp[i][j] += dp[i][j-1];
            }
        }
        for(int i = m-1; i >= 1; i--){
            boolean res = true;
            for(int j = 0; j <= n; j++){
                if(k <= dp[i][j]){
                    res = false;
                    pos[j]++;
                    if(j != 0) k -= (int)dp[i][j-1];
                    break;
                }
            }
            if(res){
                System.out.println(-1);
                return;
            }
        }
        if(k > n+1){
            System.out.println(-1);
            return;
        }
        pos[k-1]++;
        for(int i = n; i >= 0; i--){
            while(pos[i]-->0) System.out.print('z');
            if(i != 0) System.out.print('a');
        }
    }
}
