import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main_7579 {
    static int n, m, cSum = 0;
    static int[] dp;
    static App[] arr;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken()); m = Integer.parseInt(st.nextToken());
        arr = new App[n];
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++) {
            arr[i] = new App();
            arr[i].b = Integer.parseInt(st.nextToken());
        }
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++){
            arr[i].c = Integer.parseInt(st.nextToken());
            cSum += arr[i].c;
        }
        dp = new int[cSum+1];
        dp[arr[0].c] = arr[0].b;
        for(int i = 1; i < n; i++){
            for(int j  = cSum; j >= 0; j--){
                if(j - arr[i].c >= 0 && dp[j-arr[i].c] + arr[i].b > dp[j]){
                    dp[j] = dp[j-arr[i].c] + arr[i].b;
                }
            }
        }
        for(int i = 0; i <= cSum; i++){
            if(dp[i] >= m){
                System.out.println(i);
                break;
            }
        }
    }

    static class App{
        int b, c;
    }
}
