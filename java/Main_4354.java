import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main_4354 {
    static char[] str;
    static int[] pi;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        str = br.readLine().toCharArray();
        int slen = str.length;
        pi = new int[slen];
        int j = 0;
        for(int i = 1; i <slen; i++){
            while(j > 0 && str[i] != str[j]) j = pi[j-1];
            if(str[i] == str[j]) pi[i] = ++j;
        }
        System.out.println(Arrays.toString(pi));
    }
}
