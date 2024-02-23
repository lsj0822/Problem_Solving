#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, k, b[100005], ans = -1;
vector<int> V;
int main(void)
{
  cin >> n >> k;
  V.push_back(0);
  for(int i = 1; i < n; i++){
    int a;
    cin >> a;
    if(a > k) V.push_back(i);
  }
  V.push_back(n);
  if(V.size() == 2) ans = n;
  for(int i = 0; i < V.size() - 2; i++){
    ans = max(ans, V[i+2]-V[i]);
  }
  cout << ans;
  return 0;
}