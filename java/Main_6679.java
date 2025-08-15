public class Main_6679 {
    public static void main(String[] args) {
        StringBuilder sb = new StringBuilder();
        for(int i = 1000; i < 10000; i++){
            int d10 = digits(i, 10), d12 = digits(i, 12), d16 = digits(i, 16);
            if(d10 == d12 && d12 == d16) sb.append(i).append("\n");
        }
        System.out.print(sb.toString());
    }

    static int digits(int num, int d){
        int res = 0;
        while(num > 0){
            res += num%d;
            num /= d;
        }
        return res;
    }
}
