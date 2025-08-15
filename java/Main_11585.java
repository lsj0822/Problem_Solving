import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main_11585 {
    static int n, ans = 0;
    static char[] target, dollim;
    static int[] pi;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        n = Integer.parseInt(br.readLine());
        target = new char[n]; dollim = new char[2*n-1];
        pi = new int[n];
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++){
            target[i] = st.nextToken().charAt(0);
        }
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++){
            dollim[i] = st.nextToken().charAt(0);
            if (i != n - 1) dollim[i+n] = dollim[i];
        }
        int j = 0;
        for(int i = 1; i < n; i++){
            while(j > 0 && target[i] != target[j]) j = pi[j-1];
            if(target[i] == target[j]) pi[i] = ++j;
        }
        j = 0;
        for(int i = 1; i < 2*n-1; i++){
            while(j > 0 && dollim[i] != target[j]) j = pi[j-1];
            if(dollim[i] == target[j]) j++;
            if(j == n){
                ans++;
                j = pi[j-1];
            }
        }
        System.out.println((ans/gcd(ans,n)) + "/" + (n/gcd(ans,n)));
    }

    static int gcd(int a, int b){
        if(b == 0) return a;
        return gcd(b, a%b);
    }
}
