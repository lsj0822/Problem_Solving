import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class Main_19699 {
    static int n, m;
    static int[] arr;
    static boolean[] isPrime = new boolean[10001];
    static TreeSet<Integer> ans = new TreeSet<>();
    public static void main(String[] args) throws IOException {
        findPrime();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();
        n = Integer.parseInt(st.nextToken()); m = Integer.parseInt(st.nextToken());
        arr = new int[n];
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++) arr[i] = Integer.parseInt(st.nextToken());
        backTracking(0, 0, 0);
        if(ans.size() == 0) System.out.println(-1);
        else{
            for(int i : ans) sb.append(i + " ");
            System.out.println(sb.toString());
        }
    }

    static void backTracking(int dep, int idx, int val){
        if(dep == m){
            if(isPrime[val]) ans.add(val);
            return;
        }
        for(int i = idx; i < n; i++) backTracking(dep+1, i+1, val+arr[i]);
    }

    static void findPrime(){
        Arrays.fill(isPrime, true);
        for(int i = 2; i <= 100; i++){
            if(!isPrime[i]) continue;
            for(int j = 2; i*j <= 10000; j++) isPrime[i*j] = false;
        }
    }
}
