#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> GMS;
int st, en, container[10];

void bt(int dep){
  if(dep >= 9) return;
  for(int i : {4, 7}){
    container[dep] = i;
    int addednum = container[0];
    for(int r = 1; r <= dep; r++){
      addednum *= 10;
      addednum += container[r];
    }
    GMS.push_back(addednum);
    bt(dep+1);
  }
}
int main(void)
{
  bt(0);
  sort(GMS.begin(), GMS.end());
  int a, b;
  cin >> a >> b;
  cout << (lower_bound(GMS.begin(), GMS.end(), b+1) - GMS.begin()) - (lower_bound(GMS.begin(), GMS.end(), a) - GMS.begin());
  return 0;
}