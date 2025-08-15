import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main_21342 {
    static int n;
    static Drone[] drones;
    static boolean[] isCrashed;
    static PriorityQueue<CrashInfo> pq = new PriorityQueue<>((o1,o2)->Long.compare(o1.num*o2.den, o2.num*o1.den));
    static ArrayList<Integer> survivedDrone = new ArrayList<>();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        n = Integer.parseInt(br.readLine());
        drones = new Drone[n]; isCrashed = new boolean[n];
        for(int i = 0; i < n; i++){
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken()), v = Integer.parseInt(st.nextToken()), prv = -1, nxt = -1;
            if(i != 0) prv = i-1;
            if(i != n-1) nxt = i+1;
            drones[i] = new Drone(x,v,prv,nxt);
            if(i != 0) findCrashTime(i-1, i);
        }
        while(!pq.isEmpty()){
            CrashInfo cur = pq.poll();
            int d1 = cur.d1, d2 = cur.d2;
            if(isCrashed[d1] || isCrashed[d2]) continue;
            isCrashed[d1] = true; isCrashed[d2] = true;
            Drone dd1 = drones[d1], dd2 = drones[d2];
            if(dd1.prv != -1) drones[dd1.prv].nxt = dd2.nxt;
            if(dd2.nxt != -1) drones[dd2.nxt].prv = dd1.prv;
            if(dd1.prv != -1 && dd2.nxt != -1) findCrashTime(dd1.prv, dd2.nxt);
        }
        for(int i = 0; i < n; i++){
            if(!isCrashed[i]) survivedDrone.add(i+1);
        }
        sb.append(survivedDrone.size() + "\n");
        for(Integer i : survivedDrone) sb.append(i + " ");
        System.out.println(sb.toString());
    }

    static void findCrashTime(int p, int c){
        Drone pd = drones[p], cd = drones[c];
        if(pd.vel <= cd.vel) return;
        pq.add(new CrashInfo(p,c,cd.pos-pd.pos, pd.vel - cd.vel));
    }

    static class Drone {
        int pos, vel, prv, nxt;
        public Drone(int pos, int vel, int prv, int nxt) {
            this.pos = pos; this.vel = vel; this.prv = prv; this.nxt = nxt;
        }
    }

    static class CrashInfo{
        int d1, d2;
        long num, den;
        public CrashInfo(int d1, int d2, long num, long den){
            this.d1 = d1; this.d2 = d2; this.num = num; this.den = den;
        }
    }
}
