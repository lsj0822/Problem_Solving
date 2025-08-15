import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main_12886 {
    static HashSet<Integer> hash = new HashSet<>();
    static final int D = 1000, DD = (int)1e6;
    static int a,b,c;
    static boolean res = false;
    static Queue<Integer> que = new LinkedList<>();

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        a = sc.nextInt(); b = sc.nextInt(); c = sc.nextInt();
        if((a+b+c)%3 != 0){
            System.out.println(0);
            return;
        }
        hash.add(a*DD+b*D+c);
        que.add(a*DD+b*D+c);
        while(!que.isEmpty()){
            int cur = que.poll();
            int a = cur/DD, b = (cur/D)%D, c = cur%D;
            if(a == b && b == c){
                res = true;
                break;
            }
            int nxtA, nxtB, nxtC, nxtHash;
            if(a > b){nxtA = a-b; nxtB = b+b;}
            else{nxtA = a+a; nxtB = b-a;}
            nxtHash = nxtA*DD + nxtB*D + c;
            if(!hash.contains(nxtHash)){
                que.add(nxtHash);
                hash.add(nxtHash);
            }
            if(b > c){nxtB = b-c; nxtC = c+c;}
            else{nxtB = b+b; nxtC = c-b;}
            nxtHash = a*DD + nxtB*D + nxtC;
            if(!hash.contains(nxtHash)){
                que.add(nxtHash);
                hash.add(nxtHash);
            }
            if(a > c){nxtA = a-c; nxtC = c+c;}
            else{nxtA = a+a; nxtC = c-a;}
            nxtHash = nxtA * DD + b*D + nxtC;
            if(!hash.contains(nxtHash)){
                que.add(nxtHash);
                hash.add(nxtHash);
            }
        }
        System.out.println(res?1:0);
    }
}
