#include <iostream>
#include <deque>
using namespace std;
int n, arr[1005];
deque<int> dq;
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    for(int i = 1; i <= n; i++) dq.push_back(i);
    while(dq.size() > 2){
        int res = dq.front();
        cout << res << ' ';
        dq.pop_front();
        if(arr[res] > 0){
            for(int i = 0; i < arr[res]-1; i++){
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        else{
            for(int i = 0; i < -arr[res]; i++){
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }
    cout << dq.front() << ' ' << dq.back();
    return 0;
}