import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main_12866 {
    static long[] cnt = new long[4];
    static int n;
    static char[] arr, dna = {'A','C','G','T'};
    static final int MOD = (int)1e9+7;
    static long ans = 1L;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        arr = br.readLine().toCharArray();
        for(char c : arr){
            for(int i = 0; i < 4; i++){
                if(c == dna[i]) cnt[i]++;
            }
        }
        for(int i = 0; i < 4; i++) ans = (ans*cnt[i]) % MOD;
        System.out.println(ans);
    }
}
