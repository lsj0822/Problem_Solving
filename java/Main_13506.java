import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main_13506 {
    static char[] str;
    static int[] pi;
    static int ans = -1;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        str = br.readLine().toCharArray();
        pi = new int[str.length]; int j = 0;
        for(int i = 1; i < str.length; i++) {
            while(j > 0 && str[i] != str[j]) j = pi[j-1];
            if(str[i] == str[j]) pi[i] = ++j;
        }
        j = pi[str.length-1];
        while(j > 0){
            System.out.println(j);
            int cnt = countKMP(j);
            if(cnt >= 3) {
                ans = j;
                break;
            }
            j = pi[j-1];
        }
        if(ans == -1) System.out.println(ans);
        else{
            for(int i = 0; i < ans; i++) sb.append(str[i]);
            System.out.println(sb.toString());
        }
    }

    static int countKMP(int n) {
        int idx = 0, res = 0;
        for(int i = 0; i < str.length; i++){
            while(idx > 0 && str[i] != str[idx]) idx = pi[idx-1];
            if(str[i] == str[idx]) idx++;
            if(idx == n){
                res++;
                idx = pi[idx-1];
            }
        }
        return res;
    }
}
