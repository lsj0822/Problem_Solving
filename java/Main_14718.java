import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class Main_14718 {
    static int n, k, ans = Integer.MAX_VALUE;
    static Soldier[] arr;
    static TreeSet<Integer> sSet = new TreeSet<>(),
            dSet = new TreeSet<>(),
            iSet = new TreeSet<>();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken()); k = Integer.parseInt(st.nextToken());
        arr = new Soldier[n];
        for(int i = 0; i < n; i++){
            st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken()), d = Integer.parseInt(st.nextToken()), k = Integer.parseInt(st.nextToken());
            arr[i] = new Soldier(s,d,i);
            sSet.add(s); dSet.add(d); iSet.add(i);
        }
        for(int s : sSet){
            for(int d : dSet){
                for(int i : iSet){
                    if(s+d+i > ans) continue;
                    int cnt = 0;
                    for(int a = 0; a < n; a++){
                        if(arr[a].cmp(s,d,i)) cnt++;
                    }
                    if(cnt >= k) ans = s+d+i;
                }
            }
        }
        System.out.println(ans);
    }

    static class Soldier{
        int str, dex, inte;

        public Soldier(int str, int dex, int inte){
            this.str = str; this.dex = dex; this.inte = inte;
        }

        boolean cmp(int s, int d, int i){
            return str <= s && dex <= d && inte <= i;
        }
    }
}
