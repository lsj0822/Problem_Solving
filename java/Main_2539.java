import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main_2539 {
    static int h, w, lim, p, maxH = 0, ans;
    static ArrayList<Integer> arr = new ArrayList<Integer>();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        h = Integer.parseInt(st.nextToken()); w = Integer.parseInt(st.nextToken());
        lim = Integer.parseInt(br.readLine());
        p = Integer.parseInt(br.readLine());
        while(p-->0){
            st = new StringTokenizer(br.readLine());
            int y = Integer.parseInt(st.nextToken()), x = Integer.parseInt(st.nextToken());
            maxH = Math.max(maxH, y);
            arr.add(x);
        }
        Collections.sort(arr);
        int l = maxH, r = w;
        while(l <= r){
            int mid = (l+r)/2;
            if(countPaper(mid) <= lim){
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        System.out.println(l);
    }

    static int countPaper(int crit){
        int res = 0, srtPos = -crit;
        for(int i : arr){
            if(i-srtPos >= crit){
                srtPos = i;
                res++;
            }
        }
        return res;
    }
}
