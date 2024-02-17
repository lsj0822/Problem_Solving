#include <iostream>
#include <algorithm>
using namespace std;

int t, n, poll[50005], total;
pair<int, int> mx;
int main(void)
{
  cin >> t;
  while(t--){
    total = 0;
    fill(&poll[0], &poll[50000], 0);
    mx = {0,0};
    cin >> n;
    for(int i = 0; i < n; i++){
      int k;
      cin >> k;
      poll[k]++;
      total += k;
      if(k > mx.first) mx = {k,i+1};
    }
    if(poll[mx.first] > 1) cout << "no winner";
    else if(mx.first > total/2) cout << "majority winner " << mx.second;
    else cout << "minority winner " << mx.second;
    cout << '\n';
  }
  return 0;
}