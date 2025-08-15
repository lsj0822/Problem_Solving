import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;

public class Main_1893 {
    static int t, alen, wlen, slen;
    static int[] widx, sidx, pi;
    static HashMap<Character, Integer> seq = new HashMap<>();
    static ArrayList<Integer> ans = new ArrayList<>();
    static String a, w, s;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        t = Integer.parseInt(br.readLine());
        while(t-->0){
            seq.clear(); ans.clear();
            a = br.readLine();
            w = br.readLine();
            s = br.readLine();
            alen = a.length(); wlen = w.length(); slen = s.length();
            widx = new int[wlen]; sidx = new int[slen]; pi = new int[wlen];
            for(int i = 0; i < alen; i++) seq.put(a.charAt(i), i);
            for(int i = 0; i < wlen; i++) widx[i] = seq.get(w.charAt(i));
            for(int i = 0; i < slen; i++) sidx[i] = seq.get(s.charAt(i));

            int j = 0;
            for(int i = 1; i < wlen; i++){
                while(j > 0 && widx[i] != widx[j]) j = pi[j-1];
                if(widx[i] == widx[j]) pi[i] = ++j;
            }

            for(int i = 0; i < alen; i++){
                j = 0;
                int cnt = 0;
                for(int k = 0; k < slen; k++){
                    while(j > 0 && (sidx[k] != (widx[j]+i)%alen)) j = pi[j-1];
                    if(sidx[k] == (widx[j]+i)%alen) j++;
                    if(j == wlen){
                        cnt++;
                        j = pi[j-1];
                    }
                }
                if(cnt == 1) ans.add(i);
            }

            switch(ans.size()){
                case 0:
                    System.out.println("no solution");
                    break;
                case 1:
                    System.out.println("unique: " + ans.get(0));
                    break;
                default:
                    System.out.print("ambiguous: ");
                    for(int i : ans) System.out.print(i + " ");
                    System.out.println();
                    break;
            }
        }
    }
}
