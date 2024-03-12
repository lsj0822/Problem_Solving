#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string member[105][105];
pair<string, int> group[105];
int n, m;
int main(void)
{
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    string str;
    int k;
    cin >> str >> k;
    group[i] = {str, k};
    for(int j = 0; j < k; j++){
      cin >> member[i][j];
    }
    sort(&member[i][0], &member[i][k]);
  }
  while(m--){
    string str;
    bool flag;
    cin >> str >> flag;
    if(flag){
      for(int i = 0; i < n; i++){
        for(int j = 0; j < group[i].second; j++){
          if(member[i][j] == str){
            cout << group[i].first << '\n';
            break;
          }
        }
      }
    }
    else{
      for(int i = 0; i < n; i++){
        if(group[i].first == str){
          for(int r = 0; r < group[i].second; r++) cout << member[i][r] << '\n';
          break;
        }
      }
    }
  }
  return 0;
}