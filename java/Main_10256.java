import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main_10256 {
    static final int ROOT = 1;
    static int t, n, m, unused;
    static int[][] trie;
    static char[] structure, dna;
    static char[] dnaSeq = new char[]{'A', 'C', 'G', 'T'};
    static boolean[] endPoint;
    static int[] prv;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        t = Integer.parseInt(br.readLine());
        while(t-->0){
            st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken()); m = Integer.parseInt(st.nextToken());
            int size = (m*(m-1)/2+1)*m+3; unused = ROOT;
            trie = new int[size][4]; endPoint = new boolean[size]; prv = new int[size];
            structure = br.readLine().toCharArray();
            dna = br.readLine().toCharArray();
            makeTrie(dna);
            for(int i = 0; i < m; i++){
                for(int j = i+1; j < m; j++){
                    char[] cpy = makeDNA(i, j);
                    makeTrie(cpy);
                }
            }
            makeFailure();
            System.out.println(query());
        }
    }

    static char[] makeDNA(int l, int r){
        char[] res = new char[m];
        for(int i = 0; i < l; i++) res[i] = dna[i];
        for(int i = l; i <= r; i++) res[i] = dna[l+r-i];
        for(int i = r+1; i < m; i++) res[i] = dna[i];
        return res;
    }

    static void makeTrie(char[] arr){
        int cur = ROOT;
        for(char c : arr){
            if(trie[cur][d2i(c)] == 0) trie[cur][d2i(c)] = ++unused;
            cur = trie[cur][d2i(c)];
        }
        endPoint[cur] = true;
    }

    static int d2i(char c){
       for(int i = 0; i < 4; i++){
           if(c == dnaSeq[i]) return i;
       }
       return -1;
    }

    static void makeFailure(){
        Queue<Integer> que = new LinkedList<>();
        for(int i = 0; i < 4; i++){
            if(trie[ROOT][i] != 0){
                prv[trie[ROOT][i]] = ROOT;
                que.add(trie[ROOT][i]);
            }
        }
        while(!que.isEmpty()){
            int cur = que.poll();
            for(int i = 0; i < 4; i++){
                if(trie[cur][i] != 0){
                    int p = prv[cur], nxt = trie[cur][i];
                    while(p > ROOT && trie[p][i] == 0) p = prv[p];
                    if(trie[p][i] != 0) p = trie[p][i];
                    prv[nxt] = p;
                    if(endPoint[p]) endPoint[nxt] = true;
                    que.add(nxt);
                }
            }
        }
    }

    static int query(){
        int ans = 0, cur = ROOT;
        for(char c : structure){
            while(cur > ROOT && trie[cur][d2i(c)] == 0) cur = prv[cur];
            if(trie[cur][d2i(c)] != 0) cur = trie[cur][d2i(c)];
            if(endPoint[cur]) ans++;
        }
        return ans;
    }
}
