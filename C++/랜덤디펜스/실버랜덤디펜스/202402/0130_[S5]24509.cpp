#include <iostream>
using namespace std;

int n, k, mx, stu;
int score[200005][4], great[4];
int main(void)
{
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> k;
    for(int j = 0; j < 4; j++){
      cin >> score[k][j];
    }
  }
  for(int i = 0; i < 4; i++){
    mx = -1, stu = 0;
    for(int j = 1; j <= n; j++){
      if(mx < score[j][i]) {
        stu = j;
        mx = score[j][i];
      }
    }
    great[i] = stu;
    for(int i = 0; i < 4; i++) score[stu][i] = -1;
  }
  for(auto i : great) cout << i << " ";
  return 0;
}