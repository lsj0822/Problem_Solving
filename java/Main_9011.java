import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main_9011 {
    static int t, n;
    static boolean res;
    static int[] arr, ans;
    static boolean[] vst;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        t = Integer.parseInt(br.readLine());
        while(t-- > 0){
            res = true;
            n = Integer.parseInt(br.readLine());
            st = new StringTokenizer(br.readLine());
            arr = new int[n]; ans = new int[n]; vst = new boolean[n];
            for(int i = 0; i < n; i++) arr[i] = Integer.parseInt(st.nextToken());
            for(int i = 1; i <= n;i++) {
                boolean tmp = false;
                for (int j = n - 1; j >= 0; j--) {
                    if (arr[j] == 0 && !vst[j]) {
                        tmp = true;
                        vst[j] = true;
                        ans[j] = i;
                        break;
                    }
                    if (!vst[j]) arr[j]--;
                }
                if (!tmp) {
                    res = false;
                    break;
                }
            }
            if(res){
                for(int i = 0; i < n; i++) sb.append(ans[i] + " ");
            }
            else sb.append("IMPOSSIBLE");
            sb.append("\n");
        }
        System.out.print(sb.toString());
    }
}
