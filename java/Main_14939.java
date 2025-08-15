import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main_14939 {
    static int[] bulbs = new int[10];
    static int ans = Integer.MAX_VALUE;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        for(int i = 0; i < 10; i++){
            char[] c = br.readLine().toCharArray();
            for(int j = 0; j < 10; j++){
                if(c[j] == 'O') bulbs[i] += (1<<j);
            }
        }
        for(int i = 0; i < (1<<10); i++) ans = Math.min(ans, bitMasking(i));
        System.out.println(ans==Integer.MAX_VALUE?-1:ans);
    }

    static int bitMasking(int seed){
        int[] cpy = Arrays.copyOf(bulbs, bulbs.length);
        int res = 0;
        for(int i = 0; i < 10; i++){
            if((seed & (1<<i)) != 0){
                res++;
                cpy[1] ^= (1<<i);
                for(int j = i-1; j <= i+1; j++){
                    if(j >= 0 && j < 10) cpy[0] ^= (1<<j);
                }
            }
        }

        for(int i = 1; i < 10; i++){
            for(int j = 0; j < 10; j++){
                if((cpy[i-1] & (1<<j)) != 0){
                    res++;
                    for(int k : new int[]{i-1,i+1}){
                        if(k >= 0 && k < 10) cpy[k] ^= (1<<j);
                    }
                    for(int k : new int[]{j-1,j+1}){
                        if(k >= 0 && k < 10) cpy[i] ^= (1<<k);
                    }
                    cpy[i] ^= (1<<j);
                }
            }
        }
        if(cpy[9] != 0) res = Integer.MAX_VALUE;
        return res;
    }

}
