public class Main_15883 {
    static final int DIGIT = 16;
    static int[] d = new int[9];
    static boolean[] vst = new boolean[16];
    static char[] letter = new char[]{'L','I','S','T','F','O','A','C','K'};
    static StringBuilder sb = new StringBuilder();
    public static void main(String[] args) {
        //LIST + FILO = STACK L, I, S, T, F, O, A, C
        BT(0);
        System.out.println(sb.toString());
    }

    static void BT(int dep){
        if(dep == 9){
            if(equation()){
                System.out.println(decode("LIST"));
                sb.append(decode("LIST")).append(" + ").append(decode("FILO")).append(" = ").append(decode("STACK")).append("\n");
            }
            return;
        }
        if(dep == 2){
            if(vst[1]) return;
            vst[1] = true;
            d[2] = 1;
            BT(dep+1);
            vst[1] = false;
            return;
        }
        for(int i = 0; i < 16; i++){
            if((dep == 0 || dep == 4) && i == 0) continue;
            if(vst[i]) continue;
            d[dep] = i;
            vst[i] = true;
            BT(dep+1);
            vst[i] = false;
        }
    }

    static String decode(String s){
        String res = "";
        for(char c : s.toCharArray()){
            for(int i = 0; i < 9; i++){
                if(c == letter[i]){
                    if(d[i] >= 0 && d[i] <= 9) res += String.valueOf(d[i]);
                    else res += (char)(d[i]-10+'a');
                }
            }
        }
        return res;
    }

    static boolean equation(){
        int l1 = crypt("LIST"), l2 = crypt("FILO"), r = crypt("STACK");
        return l1 + l2 == r && (d[0] != 0 && d[2] != 0 && d[4] != 0);
    }

    static int crypt(String s){
        int res = 0;
        for(char c : s.toCharArray()){
            res = res * DIGIT;
            for(int i = 0; i < 9; i++){
                if(c == letter[i]) res += d[i];
            }
        }
        return res;
    }
}
