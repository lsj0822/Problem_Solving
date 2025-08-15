import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main_17400 {
    static int n, q;
    static long[] arr, tree;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();
        n = Integer.parseInt(st.nextToken()); q = Integer.parseInt(st.nextToken());
        int h = (int)Math.ceil(Math.log(n)/Math.log(2));
        arr = new long[n]; tree = new long[2<<h];
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++){
            int num = Integer.parseInt(st.nextToken());
            arr[i] = i%2==0?num:-num;
        }
        initTree(1, 0, n-1);
        while(q-->0){
            st = new StringTokenizer(br.readLine());
            int query = Integer.parseInt(st.nextToken()), l = Integer.parseInt(st.nextToken()), r = Integer.parseInt(st.nextToken());
            switch(query){
                case 1:
                    sb.append(Math.abs(query(1, 0, n-1, l-1, r-1)) + "\n");
                    break;
                case 2:
                    updateTree(1, 0, n-1, l-1, l%2==0?-r:r);
                    break;
            }
        }
        System.out.print(sb.toString());
    }

    static void initTree(int node, int srt, int end){
        if(srt == end){
            tree[node] = arr[srt];
            return;
        }
        int mid = (srt + end)/2;
        initTree(node*2, srt, mid);
        initTree(node*2+1, mid+1, end);
        tree[node] = tree[node*2] + tree[node*2+1];
    }

    static long query(int node, int srt, int end, int left, int right){
        if(end < left || right < srt) return 0;
        if(left <= srt && end <= right) return tree[node];
        int mid = (srt+end)/2;
        return query(node*2, srt, mid, left, right) +
                query(node*2+1, mid+1, end, left, right);
    }

    static void updateTree(int node, int srt, int end, int idx, int val){
        if(end < idx || idx < srt) return;
        if(srt == end){
            tree[node] += val;
            return;
        }
        int mid = (srt+end)/2;
        updateTree(node*2, srt, mid, idx, val);
        updateTree(node*2+1, mid+1, end, idx, val);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
}
