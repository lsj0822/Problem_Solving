#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Boyer-Moore majority vote algorithm
pair<bool,long long> BM(vector<long long> arr){
  int cnt = 0, majorcnt = 0;
  long long major;
  for (auto n : arr) {
    if (cnt == 0) major = n;
    if (major == n) cnt++;
    else cnt--;
  }
  for(auto n : arr) if(n == major) majorcnt++;
  return ((majorcnt>arr.size()/2)?make_pair(true,major):make_pair(false,static_cast<long long>(0)));
}
int n;
int main(void)
{
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  while(n--){
    vector<long long> army;
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
      long long k;
      cin >> k;
      army.push_back(k);
    }
    if(BM(army).first) cout << BM(army).second << '\n';
    else cout << "SYJKGW\n";
  }
  return 0;
}