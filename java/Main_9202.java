import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main_9202 {
    static final int ROOT = 1, WORD_SIZE = 8;
    static int unused = ROOT, totScore, wordCnt;
    static String maxWord;
    static int[] dx = {0,-1,-1,-1,0,1,1,1}, dy = {-1,-1,0,1,1,1,0,-1}, score = {0,0,0,1,1,2,3,5,11};
    static int[][] trie;
    static boolean[] endPoint, isFind;
    static char[][] board;
    static boolean[][] vst = new boolean[4][4];
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int w = Integer.parseInt(br.readLine());
        trie = new int[w*WORD_SIZE+2][26];
        endPoint = new boolean[w*WORD_SIZE+2]; isFind = new boolean[w*WORD_SIZE+2];
        while(w-->0){
            char[] str = br.readLine().toCharArray();
            makeTrie(str);
        }
        br.readLine();
        int b = Integer.parseInt(br.readLine());
        while(b-->0){
            totScore = 0; wordCnt = 0; maxWord = "";
            Arrays.fill(isFind, false);
            board = new char[4][4];
            for(int i = 0; i < 4; i++){
                char[] c = br.readLine().toCharArray();
                for(int j = 0; j < 4; j++) board[i][j] = c[j];
            }
            if(b != 0) br.readLine();
            for(int i = 0; i < 4; i++){
                for(int j = 0; j < 4; j++){
                    if(trie[ROOT][c2i(board[i][j])] == 0) continue;
                    vst[i][j] = true;
                    calcTrie(1, String.valueOf(board[i][j]),trie[ROOT][c2i(board[i][j])],i,j);
                    vst[i][j] = false;
                }
            }
            sb.append(totScore + " " + maxWord + " " + wordCnt + "\n");
        }
        System.out.print(sb.toString());
    }

    static void makeTrie(char[] str){
        int cur = ROOT;
        for(int i = 0; i < str.length; i++){
            if(trie[cur][c2i(str[i])] == 0) trie[cur][c2i(str[i])] = ++unused;
            cur = trie[cur][c2i(str[i])];
        }
        endPoint[cur] = true;
    }

    static int c2i(char c){
        return c - 'A';
    }

    static void calcTrie(int dep, String word, int cur, int x, int y){
        if(endPoint[cur] && !isFind[cur]){
            isFind[cur] = true;
            wordCnt++;
            totScore += score[dep];
            if(dep == maxWord.length() && word.compareTo(maxWord) <= 0) maxWord = word;
            if(dep > maxWord.length()) maxWord = word;
        }
        if(dep >= 8) return;
        for(int dir = 0; dir < 8; dir++){
            int nx = x + dx[dir], ny = y + dy[dir];
            if(nx < 0 || nx >= 4 || ny < 0 || ny >= 4) continue;
            if(vst[nx][ny]) continue;
            if(trie[cur][c2i(board[nx][ny])] == 0) continue;
            vst[nx][ny] = true;
            calcTrie(dep+1, word+board[nx][ny], trie[cur][c2i(board[nx][ny])], nx, ny);
            vst[nx][ny] = false;
        }
    }
}
