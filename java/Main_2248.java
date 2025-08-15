import java.util.Scanner;

public class Main_2248 {
    static long[][] dp, prefix;
    static StringBuilder sb = new StringBuilder();
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), l = sc.nextInt();
        long s = sc.nextLong();
        dp = new long[n+1][n+1]; prefix = new long[n+1][n+1];
        dp[1][0] = 1; dp[1][1] = 1; prefix[0][0] = 1;
        for(int i = 2; i <= n; i++){
            for(int j = 0; j < i; j++){
                dp[i][j+1] += dp[i-1][j];
                dp[i][j] += dp[i-1][j];
            }
        }
        for(int i = 1; i <= n; i++){
            prefix[i][0] = dp[i][0];
            for(int j = 1; j <= i; j++){
                prefix[i][j] = prefix[i][j-1] + dp[i][j];
            }
        }
        findBit(n-1, l, s-1);
        System.out.println(sb.toString());
    }
    static void findBit(int r, int c, long s){
        if(r < 0) return;
        if(prefix[r][Math.min(r,c)] <= s){
            sb.append(1);
            findBit(r-1, c-1, s-prefix[r][Math.min(r,c)]);
        }else{
            sb.append(0);
            findBit(r-1, c, s);
        }
    }
}
