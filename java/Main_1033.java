import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main_1033 {
    static int n;
    static long[] nume, domi;
    static ArrayList<int[]>[] adj;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        n = Integer.parseInt(br.readLine());
        nume = new long[n]; domi = new long[n];
        nume[0] = 1; domi[0] = 1;
        adj = new ArrayList[n];
        for(int i = 0; i < n; i++) adj[i] = new ArrayList<>();
        for(int i = 0; i < n-1; i++){
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken()), v = Integer.parseInt(st.nextToken()),
                p = Integer.parseInt(st.nextToken()), q = Integer.parseInt(st.nextToken());
            adj[u].add(new int[]{v,q,p});
            adj[v].add(new int[]{u,p,q});
        }
        Queue<Integer> que = new LinkedList<>();
        que.add(0);
        while(!que.isEmpty()){
            int cur = que.poll();
            for(int[] nxt : adj[cur]){
                int nxtPos = nxt[0];
                if(nume[nxtPos] != 0) continue;
                nume[nxtPos] = nume[cur] * nxt[1];
                domi[nxtPos] = domi[cur] * nxt[2];
                que.add(nxtPos);
            }
        }
        long lcm = 1L;
        for(int i = 0; i < n; i++) lcm = lcm * domi[i] / getGcd(lcm, domi[i]);
        for(int i = 0; i < n; i++) nume[i] *= lcm / domi[i];
        long gcd = (n==1?1:getGcd(nume[0], nume[1]));
        for(int i = 2; i < n; i++) gcd = getGcd(gcd, nume[i]);
        for(int i = 0; i < n; i++) nume[i] /= gcd;
        for(int i = 0; i < n; i++) System.out.print(nume[i] + " ");
    }

    static long getGcd(long a, long b){
        if(b == 0) return a;
        return getGcd(b, a%b);
    }
}
