#include <iostream>
#include <deque>
using namespace std;

int t, n;
char c;
int main(void)
{
  cin >> t;
  while(t--){
    deque<char> DQ;
    cin >> n >> c;
    DQ.push_front(c);
    for(int i = 1; i < n; i++){
      cin >> c;
      if(c <= DQ.front()) DQ.push_front(c);
      else DQ.push_back(c);
    }
    for(int i = 0; i < n; i++){
      cout << DQ.front();
      DQ.pop_front();
    }
    cout << '\n';
  }
  return 0;
}