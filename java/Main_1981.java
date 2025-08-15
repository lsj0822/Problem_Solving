import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main_1981 {
    static final int MX = 200;
    static final int[] dx = {-1,1,0,0}, dy = {0,0,-1,1};
    static int ans = MX, n, minVal = MX, maxVal = -1;
    static int[][] arr;
    static boolean[][] vst;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        n = Integer.parseInt(br.readLine());
        arr = new int[n][n]; vst = new boolean[n][n];
        for(int i = 0; i < n; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < n; j++){
                arr[i][j] = Integer.parseInt(st.nextToken());
                minVal = Math.min(arr[i][j], minVal);
                maxVal = Math.max(arr[i][j], maxVal);
            }
        }
        for(int i = minVal; i <= maxVal; i++){
            int left = i, right = MX;
            while(left <= right){
                int mid = (left + right)/2;
                if(BFS(i, mid)) right = mid - 1;
                else left = mid + 1;
            }
            if(left == MX + 1) continue;
            ans = Math.min(ans, left - i);
        }
        System.out.println(ans);
    }

    static boolean BFS(int minVal, int maxVal){
        if(arr[0][0] < minVal || arr[0][0] > maxVal) return false;
        for(int i = 0; i < n; i++) Arrays.fill(vst[i], false);
        Queue<int[]> que = new LinkedList<>();
        que.add(new int[]{0,0}); vst[0][0] = true;
        while(!que.isEmpty()){
            int[] cur = que.poll();
            int x = cur[0], y = cur[1];
            for(int dir = 0; dir < 4; dir++){
                int nx = x + dx[dir], ny = y + dy[dir];
                if(nx < 0 || nx >= n || ny < 0 || ny >= n || vst[nx][ny]) continue;
                if(arr[nx][ny] < minVal || arr[nx][ny] > maxVal) continue;
                vst[nx][ny] = true;
                que.add(new int[]{nx,ny});
            }
        }
        return vst[n-1][n-1];
    }
}
