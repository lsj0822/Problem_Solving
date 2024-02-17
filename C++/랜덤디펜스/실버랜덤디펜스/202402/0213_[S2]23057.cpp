#include <iostream>
#include <set>
using namespace std;

int n, arr[21], total = 0;
bool choice[21];
set<int> S;

void bt(int dep){
  if(dep == n){
    int res = 0;
    for(int i = 0; i < n; i++){
      res += choice[i] * arr[i];
    }
    S.insert(res);
    return;
  }
  for(int i : {0, 1}){
    choice[dep] = i;
    bt(dep+1);
  }
}
int main(void)
{
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> arr[i];
    total += arr[i];
  }
  bt(0);
  cout << total - S.size() + 1;
  return 0;
}