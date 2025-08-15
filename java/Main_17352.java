import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main_17352 {
    static int[] g;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int n = Integer.parseInt(br.readLine());
        g = new int[n+1];
        for(int i = 1; i <= n; i++) g[i] = i;
        for(int i = 0; i < n-2; i++){
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken()), v = Integer.parseInt(st.nextToken());
            makeUnion(u,v);
        }
        for(int i = 1; i <= n; i++){
            if(g[i] == i) System.out.print(i + " ");
        }
    }

    static int findGroup(int x){
        if(g[x] == x) return x;
        return g[x] = findGroup(g[x]);
    }

    static void makeUnion(int u, int v){
        u = findGroup(u); v = findGroup(v);
        if(u == v) return;
        if(u > v){
            int tmp = u;
            u = v;
            v = tmp;
        }
        g[v] = u;
    }
}
