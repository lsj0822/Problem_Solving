#include <iostream>
#include <vector>
#include <deque>
using namespace std;
int n;
deque<int> DQ;
vector<int> V(1000005);
int main(void)
{
  cin >> n;
  for(int i = 0; i < n; i++){
    int k;
    cin >> k;
    V[i] = k;
  }
  for(int i = 1; i <= n; i++){
    switch(V[n-i]){
      case 1:
      DQ.push_back(i);
      break;
      case 2:
      int temp;
      temp = DQ.back(); DQ.pop_back();
      DQ.push_back(i);
      DQ.push_back(temp);
      break;
      case 3:
      DQ.push_front(i);
    }
  }
  while(!DQ.empty()){
    cout << DQ.back() << ' ';
    DQ.pop_back();
  }
  return 0;
}