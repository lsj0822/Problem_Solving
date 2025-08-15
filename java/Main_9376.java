import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main_9376 {
    static int t, n, m, ans;
    static final int MX = (int) 5e8;
    static int[] dx = {-1,1,0,0}, dy = {0,0,-1,1};
    static int[][] prisoner;
    static int[][][] dist;
    static char[][] arr;
    static Queue<int[]> que = new LinkedList<>();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        t = Integer.parseInt(br.readLine());
        while(t-->0){
            st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken()); m = Integer.parseInt(st.nextToken()); ans = Integer.MAX_VALUE;
            arr = new char[n+2][m+2]; dist = new int[n+2][m+2][3]; prisoner = new int[][]{{-1,-1},{-1,-1}};
            for(int i = 1; i <= n; i++){
                char[] c = br.readLine().toCharArray();
                for(int j = 1; j <= m; j++){
                    arr[i][j] = c[j-1];
                    if(c[j-1] == '$'){
                        if(prisoner[0][0] == -1 && prisoner[0][1] == -1) prisoner[0] = new int[]{i,j};
                        else prisoner[1] = new int[]{i,j};
                    }
                }
            }
            for(int i = 0; i <= n+1; i++){
                for(int j = 0; j <= m+1; j++){
                    Arrays.fill(dist[i][j], MX);
                }
            }
            addQue(0,0,0);
            addQue(prisoner[0][0], prisoner[0][1], 1);
            addQue(prisoner[1][0], prisoner[1][1], 2);
            while(!que.isEmpty()){
                int[] cur = que.poll();
                int x = cur[0], y = cur[1], p = cur[2], w = cur[3];
                for(int dir = 0; dir < 4; dir++){
                    int nx = x + dx[dir], ny = y + dy[dir];
                    if(nx < 0 || nx >= n+2 || ny < 0 || ny >= m+2 || arr[nx][ny] == '*') continue;
                    if(arr[nx][ny] == '#'){
                        int nw = w + 1;
                        if(dist[nx][ny][p] <= nw) continue;
                        dist[nx][ny][p] = nw;
                        que.add(new int[]{nx,ny,p,nw});
                    }
                    else{
                        if(dist[nx][ny][p] <= w) continue;
                        dist[nx][ny][p] = w;
                        que.add(new int[]{nx,ny,p,w});
                    }
                }
            }
            for(int i = 0; i <= n+1; i++){
                for(int j = 0; j <= m+1; j++){
                    int res = 0;
                    for(int p = 0; p < 3; p++) res += dist[i][j][p];
                    if(arr[i][j] == '*') continue;
                    else if(arr[i][j] == '#') ans = Math.min(ans, res-2);
                    else ans = Math.min(ans, res);
                }
            }
            System.out.println(ans);
        }
    }

    static void addQue(int x, int y, int p){
        dist[x][y][p] = 0;
        que.add(new int[]{x,y,p,0});
    }
}
