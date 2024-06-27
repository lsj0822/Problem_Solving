#include <iostream>
#include <string>
using namespace std;
int n, m, answer[150], stime[150];
int main() {
    cin >> n >> m;
    while(m--){
        int c, hh, mm;
        string cx;
        cin >> c >> cx >> hh >> mm;
        if(cx == "START") stime[c] = hh*60 + mm;
        else if(cx == "STOP") answer[c] += hh*60 + mm - stime[c];
    }
    for(int i = 1; i <= n; i++){
        cout << answer[i]/60 << ' ' << answer[i]%60 << '\n';
    }
    return 0;
}