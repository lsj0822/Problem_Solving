#include <iostream>
#include <algorithm>
using namespace std;

int k;
int main(void)
{
  cin >> k;
  for(int i = 1; i <= k; i++){
    int n, score[55], lg = -1;
    cin >> n;
    for(int s = 0; s < n; s++){
      cin >> score[s];
    }
    sort(&score[0], &score[n]);
    for(int i = 0; i < n-1; i++){
      lg = max(lg, score[i+1] - score[i]);
    }
    cout << "Class " << i << '\n' << "Max " << score[n-1] << ", Min " << score[0] << ", Largest gap " << lg << '\n';
  }
  return 0;
}