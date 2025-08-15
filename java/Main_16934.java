import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main_16934 {
    static final int ROOT = 1, SIZE = 100_100;
    static int unused = 1;
    static int[][] trie = new int[SIZE*10 + 2][26];
    static int[] endPoint = new int[SIZE*10 + 2];
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(br.readLine());
        while(n-->0) sb.append(makeTrie(br.readLine())).append('\n');
        System.out.print(sb.toString());
    }

    static int c2i(char c){
        return c-'a';
    }

    static String makeTrie(String str){
        int stopIdx = 100, cur = ROOT;
        for(int i = 0; i < str.length(); i++){
            if(trie[cur][c2i(str.charAt(i))] == 0){
                stopIdx = Math.min(stopIdx,i+1);
                trie[cur][c2i(str.charAt(i))] = ++unused;
            }
            cur = trie[cur][c2i(str.charAt(i))];
        }
        endPoint[cur]++;
        if(stopIdx == 100) {
            if(endPoint[cur] == 1) return str;
            else return str.concat(String.valueOf(endPoint[cur]));
        }
        else return str.substring(0, stopIdx);
    }
}
