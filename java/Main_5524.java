import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main_5524 {
    static int n;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        n = Integer.parseInt(br.readLine());
        for(int i = 0; i < n; i++) sb.append(br.readLine().toLowerCase() + "\n");
        System.out.print(sb.toString());
    }
}
