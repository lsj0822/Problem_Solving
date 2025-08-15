import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main_8061 {
    static int n, m;
    static final int[] dx = {-1,1,0,0}, dy = {0,0,-1,1};
    static int[][] dist;
    static Queue<int[]> que = new LinkedList<>();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();
        n = Integer.parseInt(st.nextToken()); m = Integer.parseInt(st.nextToken());
        dist = new int[n][m];
        for(int i = 0; i < n; i++){
            Arrays.fill(dist[i], -1);
            char[] c = br.readLine().toCharArray();
            for(int j = 0; j < m; j++){
                if(c[j] == '1'){
                    dist[i][j] = 0;
                    que.add(new int[]{i,j});
                }
            }
        }
        while(!que.isEmpty()){
            int[] cur = que.poll();
            int x = cur[0], y = cur[1];
            for(int dir = 0; dir < 4; dir++){
                int nx = x + dx[dir], ny = y + dy[dir];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m || dist[nx][ny] != -1) continue;
                dist[nx][ny] = dist[x][y] + 1;
                que.add(new int[]{nx,ny});
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                sb.append(dist[i][j] + " ");
            }
            sb.append("\n");
        }
        System.out.print(sb.toString());
    }
}
