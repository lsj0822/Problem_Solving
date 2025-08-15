import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main_16936 {
    static int n;
    static Long[] arr;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        n = Integer.parseInt(br.readLine());
        arr = new Long[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) arr[i] = Long.parseLong(st.nextToken());
        Arrays.sort(arr, (o1,o2)->{
            if(cntThree(o1) != cntThree(o2)) return -Integer.compare(cntThree(o1), cntThree(o2));
            return Long.compare(o1,o2);
        });
        for(Long l : arr) sb.append(l + " ");
        System.out.println(sb.toString());
    }

    static int cntThree(long x){
        int res = 0;
        while(x > 0){
            if(x%3 != 0) break;
            x /= 3;
            res++;
        }
        return res;
    }
}
