#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<string> ext;
int main(void)
{
  cin >> n;
  for(int i = 0; i < n; i++){
    string str;
    cin >> str;
    int idx = str.find('.');
    ext.push_back(str.substr(idx+1));
  }
  sort(ext.begin(), ext.end());
  int cnt = 1;
  string bf = ext[0];
  for(int i = 1; i < ext.size(); i++){
    if(bf != ext[i]){
      cout << bf << ' ' << cnt << '\n';
      cnt = 1;
      bf = ext[i];
    }
    else cnt++;
  }
  cout << bf << ' ' << cnt;
  return 0;
}