import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Main_28471 {
    static final int[] dx = {0,-1,-1,-1,0,1,1}, dy = {-1,-1,0,1,1,1,-1};
    static char[][] arr;
    static int cnt = -1, n;
    static int[] srtPos;
    static boolean[][] vst;
    static Queue<int[]> que = new LinkedList<>();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        arr = new char[n][n]; vst = new boolean[n][n];
        for (int i = 0; i < n; i++) {
            char[] c = br.readLine().toCharArray();
            for (int j = 0; j < c.length; j++) {
                arr[i][j] = c[j];
                if(arr[i][j] == 'F') srtPos = new int[]{i,j};
            }
        }
        vst[srtPos[0]][srtPos[1]] = true;
        que.add(srtPos);
        while(!que.isEmpty()) {
            cnt++;
            int[] cur = que.poll();
            int x = cur[0], y = cur[1];
            for(int dir = 0; dir < 7; dir++){
                int nx = x + dx[dir], ny = y + dy[dir];
                if(nx < 0 || nx >= n || ny < 0 || ny >= n || arr[nx][ny] == '#' || vst[nx][ny]) continue;
                vst[nx][ny] = true;
                que.add(new int[]{nx,ny});
            }
        }
        System.out.println(cnt);
    }
}
