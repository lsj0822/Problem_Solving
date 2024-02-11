#include <iostream>
#include <algorithm>
using namespace std;

int t, res[1005], m[205], score[205][3], n, score_idx = 1;
int main(void)
{
  cin >> t;
  while(t--){
    fill(&res[0], &res[1000], 0);
    fill(&m[0], &m[201], 0);
    fill(&score[0][0], &score[200][2], 0);
    int score_idx = 1;
    pair<int ,int> ans = {-1,6005};
    cin >> n;
    for(int i = 0; i < n; i++){
      int k;
      cin >> k;
      m[k]++;
      res[i] = k;
    }
    for(int i = 0; i < n; i++){
      int team = res[i];
      if(m[team] == 6){
        if(score[team][1] < 4){
          score[team][0] += score_idx;
          score[team][1]++;
        }
        else if(score[team][1] == 4){
          score[team][2] = score_idx;
          score[team][1]++;
        }
        score_idx++;
      }
    } 
    for(int i = 1; i <= 200; i++){
    if(score[i][0] && score[i][0] < ans.second) ans = {i, score[i][0]};
    else if(score[i][0] == ans.second){
      if(score[i][2] < score[ans.first][2]) ans = {i, score[i][0]};
    }
  }
  cout << ans.first << '\n';
}

  return 0;
}