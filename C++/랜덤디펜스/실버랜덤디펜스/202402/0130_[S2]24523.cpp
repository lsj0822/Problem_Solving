#include <iostream>
#include <queue>
using namespace std;

int n;
int ct[1000005];
queue<int> Q;

int main(void)
{
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> ct[i];
  }
  for(int i = 1; i < n; i++){
    if(ct[i] != ct[i-1]) Q.push(i);
  }
  for(int i = 0; i < n; i++){
    if(Q.size() != 0) cout << Q.front() + 1 << ' ';
    else cout << -1 << ' ';
    if (Q.front() == i+1) Q.pop();
  }
  return 0;
}