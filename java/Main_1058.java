import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main_1058 {
    static boolean[][] friend, ins;
    static int n, ans = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        friend = new boolean[n][n]; ins = new boolean[n][n];
        for(int i = 0; i < n; i++){
            char[] c = br.readLine().toCharArray();
            for(int j = 0; j < n; j++) friend[i][j] = (c[j]=='Y');
        }
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(i == j) continue;
                    ins[i][j] = ins[i][j] || (friend[i][k] && friend[k][j]);
                }
            }
        }
        for(int i = 0; i < n; i++){
            int res = 0;
            for(int j = 0; j < n; j++) res += (friend[i][j]||ins[i][j])?1:0;
            ans = Math.max(ans, res);
        }
        System.out.println(ans);
    }
}
