import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Main_9934{
    static int k;
    static int[] arr;
    static Queue<int[]> que = new LinkedList<>();
    static StringBuilder sb = new StringBuilder();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        k = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        arr = new int[(1<<k)-1];
        for(int i = 0; i < (1<<k)-1; i++) arr[i] = Integer.parseInt(st.nextToken());
        int dep = k-1;
        que.add(new int[]{((1<<k)-1)/2, k-1});
        while(!que.isEmpty()){
            int[] cur = que.poll();
            int curVal = cur[0], curDep = cur[1];
            if(curDep != dep){
                sb.append("\n");
                dep = curDep;
            }
            sb.append(arr[curVal] + " ");
            if(dep != 0){
                que.add(new int[]{curVal - (1<<(curDep-1)), curDep-1});
                que.add(new int[]{curVal + (1<<(curDep-1)), curDep-1});
            }
        }
        System.out.println(sb.toString());
    }

}	