import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main_2034 {
    static final int OCTAVE = 12;
    static char[] chord = new char[OCTAVE];
    static int[] pos = {0,2,3,5,7,8,10}, diff;
    static int n;
    public static void main(String[] args) throws IOException {
        Arrays.fill(chord, ' ');
        for(int i = 0; i < 7; i++) chord[pos[i]] = (char)('A' + i);
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        n = Integer.parseInt(br.readLine());
        diff = new int[n];
        for(int i = 0; i < n; i++) diff[i] = Integer.parseInt(br.readLine());
        for(int i = 0; i < 7; i++){
            int cur = pos[i]; boolean res = true;
            for(int j = 0; j < n; j++){
                cur = (cur+OCTAVE*3+diff[j])%OCTAVE;
                if(chord[cur] == ' ') res = false;
            }
            if(res) sb.append(chord[pos[i]] + " " + chord[cur] + "\n");
        }
        System.out.print(sb.toString());
    }
}
