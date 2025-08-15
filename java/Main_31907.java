import java.util.Scanner;

public class Main_31907 {
    static int n;
    static char[][] gist = new char[][]{{'G','.','.','.'},{'.','I','.','T'},{'.','.','S','.'}};
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        StringBuilder sb = new StringBuilder();
        n = sc.nextInt();
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < n; j++){
                for(int k = 0; k < 4; k++){
                    for(int l = 0; l < n; l++){
                        sb.append(gist[i][k]);
                    }
                }
                sb.append("\n");
            }
        }
        System.out.println(sb.toString());
    }
}
