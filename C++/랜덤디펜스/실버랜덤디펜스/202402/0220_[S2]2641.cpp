#include <iostream>
using namespace std;
int shape[55], compare[105][55], ans[105][55], idx = 0, n, m;
int main(void)
{
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> shape[i];
  }
  cin >> m;
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      cin >> compare[i][j];
    }
  }
  for(int i = 0; i < m; i++){
    //정방향 확인
    for(int f = 0; f < n; f++){
      bool res = true;
      for(int p = 0; p < n; p++){
        if(shape[(f+p)%n] != compare[i][p]) {
          res = false;
          break;
        }
      }
      if(res){
        for(int a = 0; a < n; a++){
          ans[idx][a] = compare[i][a];
        }
        idx++;
      } 
    }

    //역방향 확인
    for(int b = 0; b < n; b++){
      bool res = true;
      for(int p = 0; p < n; p++){
        if(shape[(n+b-p)%n]%2 != compare[i][p]%2 || shape[(n+b-p)%n] == compare[i][p]){
          res = false;
          break;
        }
      }
      if(res){
        for(int a = 0; a < n; a++){
          ans[idx][a] = compare[i][a];
        }
        idx++;
      } 
    }
  }
  cout << idx << '\n';
  for(int i = 0; i < idx; i++){
    for(int j = 0; j < n; j++){
      cout << ans[i][j] << " ";
    }
    cout << '\n';
  }
  return 0;
}