import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main_28122 {
    static final int BIT = 60, ROOT = 1;
    static int[][] trie;
    static int[] cnt;
    static int n, ans = 0, unused = ROOT;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        n = Integer.parseInt(br.readLine());
        int arrSize = n*(BIT+1)+2;
        trie = new int[arrSize][2]; cnt = new int[arrSize];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) makeTrie(Long.parseLong(st.nextToken()));
        DFS(ROOT, 0, 0);
        System.out.println(ans);
    }

    static void DFS(int cur, int dep, int curCnt){
        if (cur == 0 || cnt[cur] == curCnt) {
            ans = Math.max(ans, dep);
            return;
        }
        int left = trie[cur][0], right = trie[cur][1];
        if(left == 0 && right == 0){
            ans = Math.max(ans, dep + cnt[cur] - curCnt);
            return;
        }
        if(left == 0) DFS(right, dep+1, curCnt+1);
        else if(right == 0) DFS(left, dep+1, curCnt+1);
        else {
            DFS(left, dep+1, Math.max(0, curCnt-cnt[right]) + 1);
            DFS(right, dep+1, Math.max(0, curCnt-cnt[left]) + 1);
        }
    }

    static void makeTrie(long val){
        int cur = ROOT;
        cnt[cur]++;
        for(int i = 0; i < BIT; i++){
            int bit = (int)((val>>i) & 1);
            if(trie[cur][bit] == 0) trie[cur][bit] = ++unused;
            cur = trie[cur][bit];
            cnt[cur]++;
        }
    }
}
