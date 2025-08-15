import java.util.*;

class Main_22357{
    static List<Integer> prime = new ArrayList<>();
    static int k, n;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        StringBuilder sb = new StringBuilder();
        k = sc.nextInt(); n = sc.nextInt();
        makePrime();
        for(int i = 0; i < k; i++){
            int cd = prime.get(i);
            for(int j = 1; j <= n; j++) sb.append(j*cd + " ");
            sb.append("\n");
        }
        System.out.print(sb.toString());
    }

    static void makePrime(){
        boolean[] p = new boolean[2501];
        Arrays.fill(p, true);
        for(int i = 2; i <= Math.sqrt(2500); i++){
            if(!p[i]) continue;
            for(int j = 2; i*j <= 2500; j++) p[i*j] = false;
        }
        for(int i = 2000; i <= 2500; i++){
            if(p[i]) prime.add(i);
        }
    }
}