#include <iostream>
#include <queue>
using namespace std;
int n,h,t, magic = 0;
priority_queue<int> giant;
int main(void)
{
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> h >> t;
  for(int i = 0; i < n; i++){
    int k;
    cin >> k;
    giant.push(k);
  }
  while(magic < t){
    int cur = giant.top(); giant.pop();
    if(cur < h){
      cout << "YES" << '\n' << magic;
      return 0;
    }
    cur = max(1, cur/2);
    giant.push(cur);
    magic++;
  }
  if(giant.empty() || giant.top() < h) cout << "YES" << '\n' << magic;
  else cout << "NO" << '\n' << giant.top();
  return 0;
}