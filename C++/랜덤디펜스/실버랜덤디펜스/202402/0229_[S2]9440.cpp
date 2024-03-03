#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
using namespace std;

int main(void)
{
  ios::sync_with_stdio(0); cin.tie(0);
  while(1){
    int n, arr[15], zero = 0;
    string ans1, ans2;
    cin >> n;
    if(n == 0){
      return 0;
    }
    for(int i = 0; i < n; i++){
      int k;
      cin >> k;
      if(k == 0) zero++;
      arr[i] = k;
    }
    sort(&arr[0], &arr[n]);
    if(zero == 1) swap(arr[0], arr[2]);
    if(zero >= 2) {
      swap(arr[0], arr[zero]);
      swap(arr[1], arr[zero+1]);
    }
    for(int i = 0; i < n; i+=2) ans1 += to_string(arr[i]);
    for(int i = 1; i < n; i+=2) ans2 += to_string(arr[i]);
    cout << stoi(ans1) + (n==1?0:stoi(ans2)) << '\n';
  }
}