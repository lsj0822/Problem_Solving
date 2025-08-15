import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main_13553 {
    static int n, k, sq;
    static final int MX = (int)1e5;
    static int[] arr;
    static long[] tree = new long[MX+1], ans;
    static long res = 0L;
    static PriorityQueue<int[]> pq;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();
        n = Integer.parseInt(st.nextToken()); k = Integer.parseInt(st.nextToken());
        arr = new int[n+1];
        st = new StringTokenizer(br.readLine());
        for(int i = 1; i <= n; i++) arr[i] = Integer.parseInt(st.nextToken());
        sq = (int)Math.sqrt(n);
        int h = (int)Math.ceil(Math.log(MX)/Math.log(2));
        int m = Integer.parseInt(br.readLine());
        ans = new long[m];
        pq = new PriorityQueue<>((o1,o2)->{
            if(o1[0]/sq != o2[0]/sq) return Integer.compare(o1[0]/sq, o2[0]/sq);
            return Integer.compare(o1[1], o2[1]);
        });
        for(int i = 0; i < m; i++){
            st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken()), e = Integer.parseInt(st.nextToken());
            pq.add(new int[]{s,e,i});
        }
        int srt = 1, end = 0;
        while(!pq.isEmpty()){
            int[] cur = pq.poll();
            int left = cur[0], right = cur[1], idx = cur[2];
            if(right > end) addMo(end+1, right);
            if(right < end) delMo(right+1, end);
            if(left < srt) addMo(left, srt-1);
            if(left > srt) delMo(srt, left-1);
            srt = left; end = right;
            ans[idx] = res;
        }
        for(int i = 0; i < m; i++) sb.append(ans[i] + "\n");
        System.out.print(sb.toString());
    }

    static void addMo(int srt, int end) {
        for(int i = srt; i <= end; i++) {
            res += query(Math.min(arr[i]+k, MX)) - query(Math.max(arr[i]-k-1, 0));
            update(arr[i], 1);
        }
    }

    static void delMo(int srt, int end){
        for(int i = srt; i <= end; i++){
            update(arr[i], -1);
            res -= query(Math.min(arr[i]+k, MX)) - query(Math.max(arr[i]-k-1, 0));
        }
    }

    static long query(int idx){
        long res = 0L;
        while (idx > 0) {
            res += tree[idx];
            idx -= (idx & -idx);
        }
        return res;
    }

    static void update(int idx, int diff){
        while (idx < tree.length) {
            tree[idx] += diff;
            idx += (idx & -idx);
        }
    }
}
