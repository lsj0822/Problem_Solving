import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main_25910 {
    static int n, x, ans = Integer.MAX_VALUE;
    static int[][] cnt = new int[2][20];
    static boolean[] vst;
    static boolean[][] bits;
    static ArrayList<int[]>[] adj;
    static Queue<Integer> que = new LinkedList<>();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken()); x = Integer.parseInt(st.nextToken());
        bits = new boolean[n+1][20]; adj = new ArrayList[n+1]; vst = new boolean[n+1];
        Arrays.fill(bits[1], true);
        for(int i = 1; i <= n; i++) adj[i] = new ArrayList<>();
        for(int i = 0; i < n-1; i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken()), b = Integer.parseInt(st.nextToken()), c = Integer.parseInt(st.nextToken());
            adj[a].add(new int[]{b,c});
            adj[b].add(new int[]{a,c});
        }
        que.add(1); vst[1] = true;
        while(!que.isEmpty()){
            int cur = que.poll();
            for(int[] nxt : adj[cur]){
                int nxtPos = nxt[0], nxtVal = nxt[1];
                if(vst[nxtPos]) continue;
                vst[nxtPos] = true;
                for(int i = 0; i < 20; i++){
                    bits[nxtPos][i] = ((nxtVal & (1<<i)) != 0) ^ bits[cur][i];
                }
                que.add(nxtPos);
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < 20; j++){
                cnt[bits[i][j]?0:1][j]++;
            }
        }
        for(int i = 1; i <= n; i++){
            int res = 0;
            for(int j = 0; j < 20; j++){
                res += cnt[(bits[i][j]^((x&(1<<j))!=0))?1:0][j];
            }
            ans = Math.min(ans, res);
        }
        System.out.println(ans);
    }
}
