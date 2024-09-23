#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    cin >> n;
    for(int i = 1; i*2 <= n; i++){
        int a = i, b = n-i;
        if(a == b) cout << a << ' ';
        else cout << a << ' ' << b << ' ';
    }
    cout << n;
}