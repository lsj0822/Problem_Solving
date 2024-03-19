#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
int cnt[2];
string str;
queue<int> one;
stack<int> zero;
vector<pair<int,int>> thanos;

bool thasort(pair<int,int> a, pair<int,int> b){
  return a.first < b.first;
}
int main(void)
{
  getline(cin, str);
  for(int i = 0; i < str.length(); i++){
    if(str[i] == '0') zero.push(i);
    else one.push(i);
    cnt[str[i] - '0']++;
  }
  for(int i = 0; i < cnt[0]/2; i++) zero.pop();
  for(int i = 0; i < cnt[1]/2; i++) one.pop();
  while(!zero.empty()){
    thanos.push_back({zero.top(),0});
    zero.pop();
  }
  while(!one.empty()){
    thanos.push_back({one.front(),1});
    one.pop();
  }
  sort(thanos.begin(), thanos.end(), thasort);
  for(auto c : thanos){
    cout << c.second;
  }
  return 0;
}