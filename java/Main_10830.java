import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main_10830 {
    static int n;
    static long b;
    static int[][] ans;
    static int[][][] arr;
    static final int MOD = 1000;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken()); b = Long.parseLong(st.nextToken());
        arr = new int[n][n][64]; ans = new int[n][n];
        for(int i = 0; i < n; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < n; j++){
                arr[i][j][0] = Integer.parseInt(st.nextToken());
                if((b & 1) != 0) ans[i][j] = arr[i][j][0]%MOD;
            }
        }
        if((b&1) == 0){
            for(int i = 0; i < n; i++) ans[i][i] = 1;
        }
        for(int i = 1; (1L<<i) <= b; i++){
            for(int r = 0; r < n; r++){
                for(int c = 0; c < n; c++){
                    for(int k = 0; k < n; k++){
                        arr[r][c][i] = (arr[r][c][i] + arr[r][k][i-1] * arr[k][c][i-1])%MOD;
                    }
                }
            }
            if((b & (1L<<i)) != 0){
                int[][] res = new int[n][n];
                for(int r = 0; r < n; r++){
                    for(int c = 0; c < n; c++){
                        for(int k = 0; k < n; k++){
                            res[r][c] = (res[r][c] + ans[r][k] * arr[k][c][i])%MOD;
                        }
                    }
                }
                for(int r = 0; r < n; r++){
                    for(int c = 0; c < n; c++){
                        ans[r][c] = res[r][c];
                    }
                }
            }
        }

        for(int r = 0; r < n; r++){
            for(int c = 0; c < n; c++){
                System.out.print(ans[r][c] + " ");
            }
            System.out.println();
        }
    }
}
