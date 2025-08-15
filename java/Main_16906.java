import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main_16906 {
    static final int ROOT = 1, SIZE = 1000;
    static int n, unused = ROOT;
    static int[][] trie;
    static boolean[] endPoint;
    static boolean res;
    static String[] ans;
    static ArrayList<int[]> arr = new ArrayList<>();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        n = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++) arr.add(new int[]{Integer.parseInt(st.nextToken()), i});
        trie = new int[SIZE*n+2][2]; endPoint = new boolean[SIZE*n+2]; ans = new String[n];
        Collections.sort(arr, (o1,o2)->Integer.compare(o1[0], o2[0]));
        for(int[] cur : arr){
            int curIdx = cur[1], curLen = cur[0];
            res = makeTrie(0,curLen, curIdx, "", ROOT);
        }
        if(res){
            System.out.println(1);
            for(int i = 0; i < n; i++) sb.append(ans[i]+"\n");
            System.out.print(sb.toString());
        }
        else System.out.println(-1);
    }

    static boolean makeTrie(int dep, int len, int idx, String code, int cur){
        if(dep == len){
            ans[idx] = code;
            endPoint[cur] = true;
            return true;
        }
        for(int i = 0; i < 2; i++){
            if(endPoint[trie[cur][i]]) continue;
            if(trie[cur][i] == 0) trie[cur][i] = ++unused;
            if(makeTrie(dep+1, len, idx, code+String.valueOf(i), trie[cur][i])) return true;
        }
        return false;
    }
}
