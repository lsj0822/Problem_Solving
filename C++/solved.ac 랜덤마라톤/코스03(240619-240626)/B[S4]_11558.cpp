#include<iostream>
using namespace std;
int arr[10001], t, n, ans;
int main(){
    cin >> t;
    while(t--){
        ans = 0;
       cin >> n;
        for(int i = 1; i <= n; i++) cin >> arr[i];
        int target = 1;
        while(ans <= n){
            if(target == n) break;
            target = arr[target];
            ans++;
        }
        if(ans > n) cout << 0 << '\n';
        else cout << ans << '\n';
    }
}