import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main_4195 {
    static HashMap<String, Integer> hash = new HashMap<String, Integer>();
    static final int MAX_VALUE = (int)2e5;
    static int t, n, idx;
    static int[] group = new int[MAX_VALUE+1], member = new int[MAX_VALUE+1];
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        t = Integer.parseInt(br.readLine());
        while(t-->0){
            hash.clear();
            n = Integer.parseInt(br.readLine()); idx = 0;
            for(int i = 1; i <= 2*n; i++) group[i] = i;
            Arrays.fill(member, 1);
            while(n-->0){
                st = new StringTokenizer(br.readLine());
                String u = st.nextToken(), v = st.nextToken();
                sb.append(unionGroup(u,v) + "\n");
            }
        }
        System.out.print(sb.toString());
    }

    static int unionGroup(String u, String v){
        int uIdx = hash.computeIfAbsent(u, k-> idx++), vIdx = hash.computeIfAbsent(v, k-> idx++);
        uIdx = findGroup(uIdx); vIdx = findGroup(vIdx);
        if(uIdx == vIdx) return member[uIdx];
        if(uIdx > vIdx){
            int tmp = uIdx; uIdx = vIdx; vIdx = tmp;
        }
        group[vIdx] = uIdx;
        member[uIdx] += member[vIdx];
        return member[uIdx];
    }

    static int findGroup(int x){
        if(group[x] == x) return x;
        return group[x] = findGroup(group[x]);
    }
}
