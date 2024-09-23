#include <iostream>
using namespace std;
int res[1001],t;

int gcd(int x, int y){
    if(y == 0) return x;
    else return gcd(y, x%y);
}
int main(){
  int tot = 3; res[1] = tot;
    for(int i = 2; i <= 1000; i++){
        for(int j = 1; j < i; j++) if(gcd(i,j) == 1) tot+=2;
        res[i] = tot;
    }
    cin >> t;
    while(t--){
        int k;
        cin >> k;
        cout << res[k] << '\n';
    }
}