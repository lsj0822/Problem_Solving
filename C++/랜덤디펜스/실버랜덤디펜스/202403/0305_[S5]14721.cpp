#include <iostream>
#include <math.h>
#define ll long long
using namespace std;

int n, ans = 100000005;
pair<ll,ll> pos[105];
pair<int,int> ansidx = {0,0};
int main(void)
{
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) cin >> pos[i].first >> pos[i].second;
  for(int a = 1; a <= 100; a++){
    for(int b = 1; b <= 100; b++){
      ll total = 0;
      for(int i = 0; i < n; i++){
        total += pow(pos[i].second - (a*pos[i].first + b),2);
      }
      if(ans > total){
        ans = total;
        ansidx = {a,b};
      }
    }
  }
  cout << ansidx.first << " " << ansidx.second;
  return 0;
}