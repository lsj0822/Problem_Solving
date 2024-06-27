#include <iostream>
using namespace std;
int n, arr[55], ans = 0;
bool is_finished = false;
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    while(!is_finished){
        is_finished = true;
        for(int i = 0; i < n; i++){
            if(arr[i] > 1) is_finished = false;
            if((arr[i] %2) == 1){
                arr[i]--;
                ans++;
            }
        }
        for(int i = 0; i < n; i++) arr[i] /= 2;
        if(!is_finished) ans++;
    }
    cout << ans;
    return 0;
}