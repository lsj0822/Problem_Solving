#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
using namespace std;

pair<int, string> majorbook[20];
string target;
int n, freq[26], totalfreq[26], majorfreq[20][26], cost = 1000001, mselect[11];
void bt(int dep){
  if(dep == n){
    int totalcost = 0;
    memset(totalfreq, 0, sizeof(int)*26);
    for(int i = 0; i < n; i++){
      if(mselect[i]) continue;
      totalcost += majorbook[i].first;
      for(int j = 0; j < 26; j++){
        totalfreq[j] += majorfreq[i][j];
      }
    }
    for(int i = 0; i < 26; i++){
      if(freq[i] > totalfreq[i]) return;
    }
    cost = min(cost, totalcost);
    return;
  }
  for(int i : {0,1}){
    mselect[dep] = i;
    bt(dep+1);
  }
}
int main(void)
{
  ios::sync_with_stdio(0);cin.tie(0);
  cin >> target >> n;
  for(auto c : target) freq[c - 'A']++;
  for(int i = 0; i < n; i++) cin >> majorbook[i].first >> majorbook[i].second;
  for(int i = 0; i < n; i++){
    for(auto c : majorbook[i].second) majorfreq[i][c-'A']++;
  }
  bt(0);
  if(cost == 1000001) cout << -1;
  else cout << cost;
  return 0;
}