#include <iostream>
#include <string>
#include <map>
using namespace std;

int n, ans = 0, idx = 1;
map<string,int> hj;
string hw[2505];
int main(void)
{
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++){
    string str;
    cin >> str;
    hj.insert({str,idx++});
  }
  for(int i = 0; i < n; i++) cin >> hw[i];
   for(int i = 0; i < n; i++){
     for(int j = i+1; j < n; j++){
       if((hj[hw[j]] - hj[hw[i]]) > 0) ans++;
     }
   }
  
  cout << ans << '/' << n*(n-1)/2;
  return 0;
}