import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class Main_2629 {
    static TreeSet<Integer> dp = new TreeSet<>();
    static int n, k;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        n = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        dp.add(0);
        for(int i = 0; i < n; i++){
            int w = Integer.parseInt(st.nextToken());
            if(i == 0) dp.add(w);
            else{
                ArrayList<Integer> res = new ArrayList<>();
                for(int k : dp){
                    if(k+w <= 40000) res.add(k+w);
                    res.add(Math.abs(k-w));
                }
                for(int r : res) dp.add(r);
            }
        }
        k = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        while(k-->0){
            int w = Integer.parseInt(st.nextToken());
            sb.append(dp.contains(w)?"Y":"N").append(" ");
        }
        System.out.println(sb.toString());
    }
}
