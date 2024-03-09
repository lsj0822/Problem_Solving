#include <iostream>
#include <algorithm>
using namespace std;

int n, chicken[1500000], k;
int main(void)
{
  cin >> n;
  for(int i = 0; i < n; i++) cin >> chicken[i];
  cin >> k;
  int DIV = n/k;
  for(int i = 0; i < n; i+=DIV){
    sort(&chicken[i], &chicken[i+DIV]);
    for(int j = 0; j < DIV; j++){
      cout << chicken[i+j] << ' ';
    }
  }
  return 0;
}