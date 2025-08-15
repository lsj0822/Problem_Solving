import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Map;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class Main_7432 {
    static Trie ROOT = new Trie(null, -1);
    static int n;
    static StringBuilder sb = new StringBuilder();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        n = Integer.parseInt(br.readLine());
        while(n-->0){
            st = new StringTokenizer(br.readLine(), "\\");
            ArrayList<String> ls = new ArrayList<>();
            while(st.hasMoreTokens()){
                ls.add(st.nextToken());
            }
            makeTrie(ls);
        }
        DFS(ROOT);
        System.out.print(sb.toString());
    }

    static void DFS(Trie cur){
        if(cur != ROOT){
            for(int i = 0; i < cur.dep; i++) sb.append(" ");
            sb.append(cur.dirName).append('\n');
        }
        for(Map.Entry<String, Trie> t : cur.nxt.entrySet()){
           DFS(t.getValue());
        }
    }

    static void makeTrie(ArrayList<String> ls){
        Trie cur = ROOT;
        for(String str : ls){
            cur.nxt.putIfAbsent(str, new Trie(str, cur.dep+1));
            cur = cur.nxt.get(str);
        }
    }

    static class Trie{
        String dirName;
        int dep;
        TreeMap<String, Trie> nxt;

        public Trie(String dirName, int dep){
            this.dirName = dirName;
            this.dep = dep;
            nxt = new TreeMap<>();
        }

    }
}
