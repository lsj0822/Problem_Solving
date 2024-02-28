#include <iostream>
#include <queue>
using namespace std;

int n, a;
priority_queue<int> gift;
int main(void)
{
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> a;
    if(a){
      for(int g = 0; g < a; g++){
        int k;
        cin >> k;
        gift.push(k);
      }
    }
    else{
      if(gift.empty()) cout << -1;
      else{
        cout << gift.top();
        gift.pop();
      }
      cout << '\n'; 
    }
  }
  return 0;
}