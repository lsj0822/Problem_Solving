#include <iostream>
#include <math.h>
using namespace std;
int arr[33000], t;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        bool nfind = false;
        for(int i = sqrt(n); i >= 1; i--){
            if(n%i != 0) continue;
            if((i+n/i)%2 == 1) continue;
            cout << (n/i - i)/2 << ' ' << (n/i + i)/2  << '\n';
            nfind = true;
            break;
        }
        if(!nfind) cout << "IMPOSSIBLE\n";
    }
    return 0;
}