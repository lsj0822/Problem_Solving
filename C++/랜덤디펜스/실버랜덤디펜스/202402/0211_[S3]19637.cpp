#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int n, m;

bool achieve_sort(pair<string, int> a, pair<string, int> b){
  return a.second < b.second;
}
int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  vector<pair<string, int>> achieve(n);
  for(int i = 0; i < n; i++){
    string str;
    int num;
    cin >> str >> num;
    achieve[i] = {str, num};
  }
  stable_sort(&achieve[0],&achieve[n],achieve_sort);
  for(int i = 0; i < m; i++){
    int k;
    cin >> k;
    int it = lower_bound(achieve.begin(),achieve.end(),make_pair("",k),achieve_sort) - achieve.begin();
    cout << achieve[it].first << '\n';
  }
  return 0;
}