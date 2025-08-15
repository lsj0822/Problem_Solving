import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Main_1786 {
    static char[] t, p;
    static int[] pi;
    static ArrayList<Integer> ans = new ArrayList<>();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        t = br.readLine().toCharArray(); p = br.readLine().toCharArray();
        pi = new int[p.length];
        int j = 0;
        for(int i = 1; i < p.length; i++){
            while(j > 0 && p[i] != p[j]) j = pi[j-1];
            if(p[i] == p[j]) pi[i] = ++j;
        }
        j = 0;
        for(int i = 0; i < t.length; i++){
            while(j > 0 && t[i] != p[j]) j = pi[j-1];
            if(t[i] == p[j]) j++;
            if(j == p.length) {
                ans.add(i-j+2);
                j = pi[j-1];
            }
        }
        sb.append(ans.size()).append("\n");
        for(Integer a : ans) sb.append(a + " ");
        System.out.println(sb.toString());
    }
}
