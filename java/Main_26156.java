import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main_26156 {
    static long ans = 0L;
    static final int MOD = (int)1e9 + 7;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        char[] arr = br.readLine().toCharArray();
        long[][] cnt = new long[n+1][3];
        long[] pow2 = new long[n+1];
        pow2[0] = 1;
        for(int i = 1; i <= n; i++) pow2[i] = pow2[i-1] * 2 % MOD;
        for(int i = n-1; i >= 0; i--){
            for(int j = 0; j < 3; j++){
                cnt[i][j] = cnt[i+1][j];
            }
            switch(arr[i]){
                case 'K':
                    cnt[i][0]++;
                    break;
                case 'C':
                    cnt[i][1] = (cnt[i][0]+cnt[i][1])%MOD;
                    break;
                case 'O':
                    cnt[i][2] = (cnt[i][1]+cnt[i][2])%MOD;
                    break;
                case 'R':
                    ans = (ans + pow2[i] * cnt[i][2])%MOD;
            }
        }
        System.out.println(ans);
    }
}
