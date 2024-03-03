#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int r, c, p[10], crank[10], maxp = -1, rankidx = 1;
int main(void)
{
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> r >> c;
  for(int i = 0; i < r; i++){
    string str;
    cin >> str;
    for(int j = 0; j < c; j++){
      if(str[j] >= '1' && str[j] <= '9'){
        p[stoi(str.substr(j,1))] = j;
        maxp = max(maxp, j);
        break;
      }
    }
  }
  while(maxp){
    bool rankbool = false;
    for(int i = 1; i <= 9; i++){
      if(p[i] == maxp){
        crank[i] = rankidx;
        rankbool = true;
      }
    }
    if(rankbool) rankidx++;
    maxp--;
  }
  for(int i = 1; i <= 9; i++) cout << crank[i] << '\n';
  return 0;
}