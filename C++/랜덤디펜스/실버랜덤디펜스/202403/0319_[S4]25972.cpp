#include <iostream>
#include <algorithm>
using namespace std;

int n, ans = 1;
pair<int,int> domino[500005];
bool dsort(pair<int,int> a, pair<int,int> b){
  return a.first < b.first;
}
int main(void)
{
  cin >> n;
  for(int i = 0; i < n; i++){
    int a, l;
    cin >> a >> l;
    domino[i] = {a,l};
  }
  sort(domino, domino+n, dsort);
  for(int i = 0; i < n-1; i++){
    if(domino[i].first + domino[i].second < domino[i+1].first) ans++;
  }
  cout << ans;
  return 0;
}