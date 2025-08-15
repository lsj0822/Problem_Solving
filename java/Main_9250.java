import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

public class Main_9250 {
    static final int ROOT = 1, MX_SIZE = 100;
    static int n, q, idx = ROOT;
    static int[][] trie;
    static int[] failure;
    static boolean[] isEnd;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        n = Integer.parseInt(br.readLine());
        trie = new int[MX_SIZE*n][26];
        failure = new int[MX_SIZE*n];
        isEnd = new boolean[MX_SIZE*n];
        for(int i = 1; i <= n; i++) {
            char[] c = br.readLine().toCharArray();
            makeTrie(c);
        }
        Queue<Integer> que = new LinkedList<>();
        for(int i = 0; i < 26; i++){
            if(trie[ROOT][i] != 0){
                failure[trie[ROOT][i]] = ROOT;
                que.add(trie[ROOT][i]);
            }
        }
        while(!que.isEmpty()){
            int cur = que.poll();
            for(int i = 0; i < 26; i++){
                if(trie[cur][i] != 0){
                    int p = failure[cur], nxt = trie[cur][i];
                    while(p > ROOT && trie[p][i] == 0) p = failure[p];
                    if(trie[p][i] != 0) p = trie[p][i];
                    failure[nxt] = p;
                    if(isEnd[p]) isEnd[nxt] = true;
                    que.add(nxt);
                }
            }
        }
        q = Integer.parseInt(br.readLine());
        while(q-->0){
            char[] c = br.readLine().toCharArray();
            sb.append(query(c)?"YES":"NO").append("\n");
        }
        System.out.print(sb.toString());
    }

    static int c2i(char c){
        return c-'a';
    }

    static void makeTrie(char[] str){
        int cur = ROOT;
        for(char c : str){
            if(trie[cur][c2i(c)] == 0) trie[cur][c2i(c)] = ++idx;
            cur = trie[cur][c2i(c)];
        }
        isEnd[cur] = true;
    }

    static boolean query(char[] str){
        int cur = ROOT;
        for(char c : str){
            while(cur > ROOT && trie[cur][c2i(c)] == 0) cur = failure[cur];
            if(trie[cur][c2i(c)] != 0) cur = trie[cur][c2i(c)];
            if(isEnd[cur]) return true;
        }
        return false;
    }
}
