import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;

public class Main_5052 {
    static int t, n, idx;
    static final int ROOT = 1;
    static int[][] trie;
    static ArrayList<char[]> arr = new ArrayList<>();
    static boolean[] vst;
    static boolean res;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        t = Integer.parseInt(br.readLine());
        while(t-->0){
            idx = ROOT;
            res = true;
            arr.clear();
            n = Integer.parseInt(br.readLine());
            trie = new int[n*10][10];
            vst = new boolean[n*10];
            for(int i = 0; i < n; i++){
                arr.add(br.readLine().toCharArray());
            }
            Collections.sort(arr, (o1,o2)->Integer.compare(o1.length, o2.length));
            for(char[] carr : arr){
                makeTrie(carr);
            }
            System.out.println(res?"YES":"NO");
        }
    }

    static int c2i(char c){
        return c-'0';
    }

    private static void makeTrie(char[] carr) {
        int cur = ROOT;
        for(char c : carr){
            if(vst[cur]) res = false;
            if(trie[cur][c2i(c)] == 0) trie[cur][c2i(c)] = ++idx;
            cur = trie[cur][c2i(c)];
        }
        vst[cur] = true;
    }
}
