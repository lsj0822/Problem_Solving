#include <iostream>
#include <algorithm>
using namespace std;

int n, player[100005];
long long jw;
int main(void)
{
  cin >> n >> jw;
  for(int i = 0; i < n-1; i++){
    cin >> player[i];
  }
  sort(&player[0], &player[n-1]);
  for(int i = 0; i < n-1; i++){
    if(jw > player[i]) jw += player[i];
    else{
      cout << "No";
      return 0;
    }
  }
  cout << "Yes";
  return 0;
}