import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main_15678 {
    static int n, d;
    static int[] arr;
    static long[] tree;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken()); d = Integer.parseInt(st.nextToken());
        int h = (int)Math.ceil(Math.log(n)/Math.log(2));
        tree = new long[(2<<h)]; arr = new int[n];
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++) arr[i] = Integer.parseInt(st.nextToken());
        update(1, 0, n-1, 0, arr[0]);
        for(int i = 1; i < n; i++){
            long val = query(1, 0, n-1, Math.max(0, i-d), i-1) + arr[i];
            update(1, 0, n-1, i, val);
        }
        System.out.println(tree[1]);
    }

    static void update(int node, int srt, int end, int idx, long val){
        if(idx < srt || end < idx) return;
        if(srt == end){
            tree[node] = val;
            return;
        }
        int mid = (srt+end)/2;
        update(node*2, srt, mid, idx, val);
        update(node*2+1, mid+1, end, idx, val);
        tree[node] = Math.max(tree[node*2], tree[node*2+1]);
    }

    static long query(int node, int srt, int end, int left, int right){
        if(right < srt || end < left) return 0;
        if(left <= srt && end <= right) return tree[node];
        int mid = (srt+end)/2;
        return Math.max(query(node*2, srt, mid, left, right),
                query(node*2+1, mid+1, end, left, right));
    }
}
