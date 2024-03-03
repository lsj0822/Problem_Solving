#include <bits/stdc++.h>
using namespace std;

int n, ans = 0;
pair<int,int> riding[55];
bool ridingsort(pair<int,int>a, pair<int,int>b){
  return a.second < b.second;
}
int main(void)
{
  cin >> n;
  for(int i = 0; i < n; i++){
    int a,b;
    cin >> a >> b;
    int st =  stoi(to_string(a).substr(0,2))*60 + stoi(to_string(a).substr(2));
    int en =  stoi(to_string(b).substr(0,2))*60 + stoi(to_string(b).substr(2));
    riding[i] = {st-10,en+10};
  }
  sort(&riding[0], &riding[n], ridingsort);
  ans = max(ans, riding[0].first-600);
  for(int i = 1; i < n; i++){
    if(riding[i-1].second <= riding[i].first){
      int endtime = riding[i].first;
      int starttime = riding[i-1].second;
      ans = max(ans, endtime-starttime);
    }
  }
  ans = max(ans, 1320-riding[n-1].second);
  cout << ans;
  return 0;
}