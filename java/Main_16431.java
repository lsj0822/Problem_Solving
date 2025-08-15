import java.util.Scanner;

public class Main_16431 {
    static int[][] arr = new int[3][2];
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 2; j++) arr[i][j] = sc.nextInt();
        }
        int tb = Math.max(Math.abs(arr[0][0]-arr[2][0]), Math.abs(arr[0][1]-arr[2][1]));
        int td = Math.abs(arr[1][0] - arr[2][0]) + Math.abs(arr[1][1] - arr[2][1]);
        if(tb < td) System.out.println("bessie");
        else if(tb > td) System.out.println("daisy");
        else System.out.println("tie");
    }
}
