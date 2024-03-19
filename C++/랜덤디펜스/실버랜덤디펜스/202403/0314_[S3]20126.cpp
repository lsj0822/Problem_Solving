#include <iostream>
#include <algorithm>
using namespace std;

bool csort(pair<int,int> a, pair<int,int> b){
  return a.second < b.second;
}

int n, m, s;
pair<int,int> c040[100005];
int main(void)
{
  cin >> n >> m >> s;
  for(int i = 0; i < n; i++){
    int a, b;
    cin >> a >> b;
    c040[i] = {a, a+b};
  }
  sort(&c040[0], &c040[n], csort);
  c040[n] = {s, 0};
  if(c040[0].first >= m){
    cout << 0;
    return 0;
  }
  for(int i = 1; i <= n; i++){
    if(c040[i].first - c040[i-1].second >= m){
      cout << c040[i-1].second;
      return 0;
    }
  }
  cout << -1;
  return 0;
}