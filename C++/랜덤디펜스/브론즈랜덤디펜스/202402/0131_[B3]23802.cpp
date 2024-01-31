#include <iostream>
using namespace std;

int main(void)
{
  int n;
  cin >> n;
  for(int k = 0; k < n; k++){
  for(int i = 0; i < 5*n; i++) cout << '@';
  cout << '\n';
  }
  for(int i = 0; i < 4*n; i++){
    for(int j = 0; j < n; j++) cout << '@';
    cout << '\n';
  }
}