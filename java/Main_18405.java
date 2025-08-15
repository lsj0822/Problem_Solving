import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Main_18405 {
    static int n, k, s, x, y;
    static final int[] dx ={-1,1,0,0}, dy={0,0,-1,1};
    static int[][] arr;
    static int[][] dist;
    static Queue<int[]> que = new LinkedList<>();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken()); k = Integer.parseInt(st.nextToken());
        arr = new int[n][n]; dist = new int[n][n];
        List<int[]> srtPos = new ArrayList<>();
        for(int i = 0; i < n; i++){
            st = new StringTokenizer(br.readLine());
            Arrays.fill(dist[i], Integer.MAX_VALUE);
            for(int j = 0; j < n; j++){
                arr[i][j] = Integer.parseInt(st.nextToken());
                if(arr[i][j] != 0) srtPos.add(new int[]{arr[i][j], i,j});
            }
        }
        Collections.sort(srtPos, (o1,o2)->Integer.compare(o1[0],o2[0]));
        for(int[] pos : srtPos){
            int sx = pos[1], sy = pos[2];
            dist[sx][sy] = 0;
            que.add(new int[]{sx, sy});
        }
        while(!que.isEmpty()){
            int[] cur = que.poll();
            int sx = cur[0], sy = cur[1];
            for(int dir = 0; dir < 4; dir++){
                int nx = sx + dx[dir], ny = sy + dy[dir];
                if(nx < 0 || nx >= n || ny < 0 || ny >= n || arr[nx][ny] != 0) continue;
                arr[nx][ny] = arr[sx][sy];
                dist[nx][ny] = dist[sx][sy] + 1;
                que.add(new int[]{nx, ny});
            }
        }
        st = new StringTokenizer(br.readLine());
        s = Integer.parseInt(st.nextToken()); x = Integer.parseInt(st.nextToken()); y = Integer.parseInt(st.nextToken());
        System.out.println(dist[x-1][y-1]<=s?arr[x-1][y-1]:0);
    }
}
