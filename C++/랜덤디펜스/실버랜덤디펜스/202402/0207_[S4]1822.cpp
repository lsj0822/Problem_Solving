#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int a, b, seta[500001], setb[500001], cur = 0;
vector<int> res;
int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> a >> b;
  for(int i = 0; i < a; i++) cin >> seta[i];
  for(int i = 0; i < b; i++) cin >> setb[i];
  sort(&seta[0], &seta[a]); sort(&setb[0], &setb[b]);
  for(int i = 0; i < b; i++){
    while(1){
      if(cur==a) break;
      if(seta[cur] < setb[i]) {
        res.push_back(seta[cur++]);
        continue;
      }
      else if(seta[cur] == setb[i]) cur++;
      break;
    }
  }
  while(cur<a) res.push_back(seta[cur++]);
  cout << res.size() << '\n';
  for(auto r : res) cout << r << " ";
  return 0;
}