import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main_2813 {
    static ArrayList<Integer> arr = new ArrayList<>();
    static PriorityQueue<int[]> pq = new PriorityQueue<>((o1, o2)->{
        if(Math.abs(o1[0]) != Math.abs(o2[0])) return -Integer.compare(Math.abs(o1[0]),Math.abs(o2[0]));
        return Integer.compare(o1[1], o2[1]);
    });
    static int[] ans, pos;
    static long ansVal = 0L;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        int n = Integer.parseInt(br.readLine());
        ans = new int[n]; pos = new int[n];
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++) pos[i] = Integer.parseInt(st.nextToken());
        for(int i = 0; i < n; i++){
            int diff = 0;
            if(i > 0) diff += Integer.compare(pos[i], pos[i-1]);
            if(i < n-1) diff += Integer.compare(pos[i], pos[i+1]);
            if(diff != 0) pq.add(new int[]{diff, i});
        }
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++) arr.add(Integer.parseInt(st.nextToken()));
        Collections.sort(arr, (o1, o2)->Integer.compare(o1,o2));
        int lidx =  0, ridx = n-1;
        while(!pq.isEmpty()){
            int[] cur = pq.poll();
            if(cur[0] > 0) ans[cur[1]] = arr.get(ridx--);
            else if(cur[0] < 0) ans[cur[1]] = arr.get(lidx++);
        }
        for(int i = 0; i < n; i++){
            if(ans[i] == 0){
                if(pos[i] > pos[i-1]) ans[i] = arr.get(lidx++);
                else ans[i] = arr.get(ridx--);
            }
        }
        for(int i = 1; i < n; i++) ansVal += Math.abs(ans[i] - ans[i-1]);
        sb.append(ansVal + "\n");
        for(int i = 0; i < n; i++) sb.append(ans[i] + " ");
        System.out.println(sb.toString());
    }
}
