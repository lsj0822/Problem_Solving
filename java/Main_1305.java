import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main_1305 {
    static int n, j = 0;
    static char[] arr;
    static int[] pi;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        pi = new int[n];
        arr = br.readLine().toCharArray();
        for(int i = 1; i < n; i++){
            while(j > 0 && arr[j] != arr[i]) j = pi[j-1];
            if(arr[i] == arr[j]) pi[i] = ++j;
        }
        System.out.println(n - pi[n-1]);
    }
}
