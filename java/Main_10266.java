import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main_10266 {
    static final int ANGLE = 360_000;
    static int n;
    static boolean[] clock1 = new boolean[ANGLE], clock2 = new boolean[ANGLE*2];
    static int[] pi = new int[ANGLE];
    static boolean ans = false;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        n = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++) clock1[Integer.parseInt(st.nextToken())] = true;
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++){
            int a = Integer.parseInt(st.nextToken());
            clock2[a] = true; clock2[ANGLE+a] = true;
        }
        int j = 0;
        for(int i = 1; i < ANGLE; i++){
            while(j > 0 && clock1[i] != clock1[j]) j = pi[j-1];
            if(clock1[i] == clock1[j]) pi[i] = ++j;
        }
        j = 0;
        for(int i = 0; i < ANGLE*2; i++){
            while(j > 0 && clock2[i] != clock1[j]) j = pi[j-1];
            if(clock1[j] == clock2[i]) j++;
            if(j == ANGLE){
                ans = true;
                break;
            }
        }
        System.out.println(ans?"possible":"impossible");
    }
}
