import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.sql.SQLOutput;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main_1760 {
    static int n, m, r = 1, c = 1;
    static int[][] arr, rowIdx, colIdx;
    static ArrayList<int[]> ans = new ArrayList<>();
    static ArrayList<Integer>[] adj;
    static int[] matched; static boolean[] vst;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();
        n = Integer.parseInt(st.nextToken()); m = Integer.parseInt(st.nextToken());
        arr = new int[n][m]; colIdx = new int[n][m]; rowIdx = new int[n][m];
        for(int i = 0; i < n; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < m; j++) arr[i][j] = Integer.parseInt(st.nextToken());
        }
        boolean changeIdx = false;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                switch(arr[i][j]){
                    case 0:
                        rowIdx[i][j] = changeIdx?++r:r;
                        changeIdx = false;
                        break;
                    case 2:
                        changeIdx = true;
                        break;
                }
            }
            changeIdx = true;
        }
        changeIdx = false;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                switch(arr[j][i]){
                    case 0:
                        colIdx[j][i] = changeIdx?++c:c;
                        changeIdx = false;
                        break;
                    case 2:
                        changeIdx = true;
                        break;
                }
            }
            changeIdx = true;
        }
        adj = new ArrayList[r+1];
        for(int i = 1; i <= r; i++) adj[i] = new ArrayList<>();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(arr[i][j] != 0) continue;
                adj[rowIdx[i][j]].add(colIdx[i][j]);
            }
        }

        matched = new int[c+1]; vst = new boolean[r+1];

        for(int i = 1; i <= r; i++){
            Arrays.fill(vst, false);
            DFS(i);
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(arr[i][j] == 0 && matched[colIdx[i][j]] == rowIdx[i][j]) ans.add(new int[]{i+1, j+1});
            }
        }
        sb.append(ans.size() + "\n");
        for(int[] a : ans) sb.append(a[0] + " " + a[1] + "\n");
        System.out.print(sb.toString());
    }

    static boolean DFS(int node){
        if(vst[node]) return false;
        vst[node] = true;
        for(int nxt : adj[node]){
            if(matched[nxt] == 0 || DFS(matched[nxt])){
                matched[nxt] = node;
                return true;
            }
        }
        return false;
    }
}
