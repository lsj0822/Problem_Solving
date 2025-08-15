import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main_5670 {
    static final int ROOT = 1, WORD_SIZE = (int)1e5, LETTER_SIZE = (int)1e6;
    static int[][] trie = new int[LETTER_SIZE+2][26];
    static boolean[] endPoint = new boolean[LETTER_SIZE+2];
    static int[] freq = new int[LETTER_SIZE+2];
    static int n, cnt, unused;
    static String[] arr = new String[WORD_SIZE];
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;
        while((line = br.readLine()) != null) {
            n = Integer.parseInt(line);
            cnt = 0;
            unused = ROOT;
            for(int i = 1; i <= WORD_SIZE+1; i++) Arrays.fill(trie[i], 0);
            Arrays.fill(endPoint, false);
            Arrays.fill(freq, 0);
            for(int i = 0; i < n; i++){
                arr[i] = br.readLine();
                char[] c = arr[i].toCharArray();
                makeTrie(c);
            }
            for(int i = 0; i < n; i++){
                cnt += countTrie(arr[i].toCharArray());
            }
            System.out.println(String.format("%.2f", cnt/(double)n));
        }
    }

    static int countTrie(char[] str){
        int cur = trie[ROOT][c2i(str[0])], res = 1;
        for(int i = 1; i < str.length; i++){
            char c = str[i];
            if(endPoint[cur] || freq[cur] > 1) res++;
            cur = trie[cur][c2i(c)];
        }
        return res;
    }

    static void makeTrie(char[] str){
        int cur = ROOT;
        for(char c : str){
            if(trie[cur][c2i(c)] == 0){
                trie[cur][c2i(c)] = ++unused;
                freq[cur]++;
            }
            cur = trie[cur][c2i(c)];
        }
        freq[cur]++;
        endPoint[cur] = true;
    }

    static int c2i(char c){
        return c-'a';
    }
}
