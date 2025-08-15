import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main_31914 {
    static int n, k, res = 0, curColor = 0, ans = 0;
    static int[] colorCnt;
    static int[] state;
    static int xCrit = -1, yCrit = Integer.MAX_VALUE;
    static Magic[] arr;
    static PriorityQueue<Magic> xpq = new PriorityQueue<>((o1,o2)-> {
        if(o1.x != o2.x) return Integer.compare(o1.x, o2.x);
        return Integer.compare(o1.y, o2.y);
    }),
        ypq = new PriorityQueue<>((o1,o2)->-Integer.compare(o1.y, o2.y));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken()); k = Integer.parseInt(st.nextToken());
        colorCnt = new int[k+1]; state = new int[n]; arr = new Magic[n];
        for(int i = 0; i < n; i++){
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken()), y = Integer.parseInt(st.nextToken()),
            power = Integer.parseInt(st.nextToken()), c = Integer.parseInt(st.nextToken());
            arr[i] = new Magic(x, y, power, c, i);
            xpq.add(arr[i]); ypq.add(arr[i]);
        }
        while(!xpq.isEmpty()){
            Magic cur = xpq.poll();
            if(cur.x != xCrit){
                xCrit = cur.x;
                ans = Math.max(ans, res);
            }
            if(state[cur.idx] != 0) continue;
            state[cur.idx] = 1;
            if(colorCnt[cur.col] == 0) curColor++;
            colorCnt[cur.col]++;
            res += cur.pow;
            if(curColor == k){
                yCrit = cur.y;
                removeMagic();
            }
        }
        System.out.println(Math.max(res, ans));
    }

    static void removeMagic(){
        while(!ypq.isEmpty() && ypq.peek().y >= yCrit){
            Magic cur = ypq.poll();
            if(state[cur.idx] == 1){
                res -= cur.pow;
                if(colorCnt[cur.col] == 1) curColor--;
                colorCnt[cur.col]--;
            }
            state[cur.idx] = 2;
        }
        ans = Math.max(res, ans);
        if(curColor == k){
            yCrit = ypq.peek().y;
            removeMagic();
        }
    }

    static class Magic{
        int x, y, pow, col, idx;
        public Magic(int x, int y, int pow, int col, int idx){
            this.x = x; this.y = y; this.pow = pow; this.col = col; this.idx = idx;
        }
    }
}
