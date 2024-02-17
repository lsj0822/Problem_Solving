#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n;
pair<string, string> mentor[100005];

bool mentorsort(pair<string, string> a, pair<string, string> b){
  if(a.first != b.first) return a.first < b.first;
  else return a.second > b.second;
}

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++){
    string a, b;
    cin >> a >> b;
    mentor[i] = {a, b};
  }
  sort(&mentor[0], &mentor[n], mentorsort);
  for(int i = 0; i < n; i++){
    cout << mentor[i].first << " " << mentor[i].second << '\n';
  }
  return 0;
}