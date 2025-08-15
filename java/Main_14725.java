import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Map;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class Main_14725 {
    static int n;
    static Trie ROOT = new Trie(null, -1);
    static StringBuilder sb = new StringBuilder();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        n = Integer.parseInt(br.readLine());
        while(n-->0){
            st = new StringTokenizer(br.readLine());
            int k = Integer.parseInt(st.nextToken());
            Trie cur = ROOT;
            for(int i = 0; i < k; i++){
                String str = st.nextToken();
                cur.child.putIfAbsent(str, new Trie(str, cur.depth+1));
                cur = cur.child.get(str);
            }
        }
        DFS(ROOT);
        System.out.print(sb.toString());
    }

    static void DFS(Trie t){
        if(t.depth != -1){
            for(int i = 0; i < 2*t.depth; i++) sb.append("-");
            sb.append(t.name).append("\n");
        }
        for(Map.Entry<String, Trie> child : t.child.entrySet()){
            DFS(child.getValue());
        }
    }

    static class Trie{
        String name;
        int depth;
        TreeMap<String, Trie> child;

        public Trie(String name, int depth){
            this.name = name;
            this.depth = depth;
            child = new TreeMap<>();
        }
    }
}
