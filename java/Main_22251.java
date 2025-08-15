import java.util.Arrays;
import java.util.Scanner;

public class Main_22251 {
    static int n, k, p, x, ans = 0;
    static boolean[][] segment = new boolean[][]{{true,true,true,true,true,true,false},
            {false,true,true,false,false,false,false},
            {true, true, false, true, true, false, true},
            {true, true, true, true, false, false, true},
            {false, true, true, false, false, true, true},
            {true, false, true, true, false, true, true},
            {true, false, true, true, true, true, true},
            {true, true, true, false, false, false, false},
            {true, true, true, true, true, true, true},
            {true, true, true, true, false, true, true}};
    static int[][] digitXOR = new int[10][10];
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt(); k = sc.nextInt(); p = sc.nextInt(); x = sc.nextInt();
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                int cnt = 0;
                for(int k = 0; k < 7; k++) cnt += (segment[i][k] ^ segment[j][k])?1:0;
                digitXOR[i][j] = cnt;
            }
        }
        BT(0, 0, intParser(x));
        System.out.println(ans);
    }

    static int[] intParser(int x){
        int[] res = new int[k];
        for(int i = k-1; i >= 0; i--){
            res[i] = x % 10;
            x /= 10;
        }
        return res;
    }

    static void BT(int dep, int changeCnt, int[] digits){
        if(changeCnt > p) return;
        if(dep == k){
            if(changeCnt == 0) return;
            if(stoi(digits) >= 1 && stoi(digits) <= n) ans++;
            return;
        }
        for(int i = 0; i < 10; i++){
            int bf = digits[dep], diff = digitXOR[i][bf];
            digits[dep] = i;
            BT(dep + 1, changeCnt + diff, digits);
            digits[dep] = bf;
        }
    }

    static int stoi(int[] digits){
        int res = 0;
        for(int c : digits){
            res = res*10 + c;
        }
        return res;
    }
}
