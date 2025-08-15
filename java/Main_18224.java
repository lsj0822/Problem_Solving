import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main_18224 {
    static boolean[][] arr;
    static int[][][] dist;
    static int[] dx = {-1,1,0,0}, dy = {0,0,-1,1};
    static int n, m;
    static Queue<int[]> que = new LinkedList<>();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken()); m = Integer.parseInt(st.nextToken());
        arr = new boolean[n][n]; dist = new int[n][n][2*m];
        for(int i = 0; i < n; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < n; j++){
                Arrays.fill(dist[i][j], -1);
                arr[i][j] = (Integer.parseInt(st.nextToken())==1);
            }
        }
        dist[0][0][0] = 0;
        que.add(new int[]{0,0,0});
        while(!que.isEmpty()){
            int[] cur = que.poll();
            int x = cur[0], y = cur[1], curDist = dist[x][y][cur[2]], curDay = cur[2], day = (cur[2]+1)%(2*m);
            for(int dir = 0; dir < 4; dir++){
                int nx = x + dx[dir], ny = y + dy[dir];
                if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if(arr[nx][ny]){
                    if((curDay/m)%2 == 0) continue;
                    while(true){
                        nx += dx[dir]; ny += dy[dir];
                        if(nx < 0 || nx >= n || ny < 0 || ny >= n) break;
                        if(!arr[nx][ny]){
                            if(dist[nx][ny][day] != -1) break;
                            else{
                                dist[nx][ny][day] = curDist + 1;
                                que.add(new int[]{nx,ny, dist[nx][ny][day]%(2*m)});
                                break;
                            }
                        }
                    }
                }
                else{
                    if(dist[nx][ny][day] != -1) continue;
                    dist[nx][ny][day] = curDist + 1;
                    que.add(new int[]{nx,ny,dist[nx][ny][day]%(2*m)});
                }
            }
        }
        int minDay = Integer.MAX_VALUE;
        for(int i = 0; i < 2*m; i++){
            if(dist[n-1][n-1][i] != -1) minDay = Math.min(minDay, dist[n-1][n-1][i]);
        }
        if(minDay == Integer.MAX_VALUE) System.out.println(-1);
        else{
            int day = minDay/m;
            System.out.println((day/2 + 1) + " " + (day%2==0?"sun":"moon"));
        }
    }
}
