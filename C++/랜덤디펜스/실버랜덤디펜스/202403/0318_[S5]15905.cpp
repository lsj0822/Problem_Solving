#include <iostream>
#include <algorithm>
using namespace std;

int n, ans = 0;
pair<int,int> score[100];

bool scoresort(pair<int,int> a, pair<int,int> b){
  if(a.first != b.first) return a.first > b.first;
  else return a.second < b.second;
}
int main(void)
{
  cin >> n;
  for(int i = 0; i < n; i++){
    int a, b;
    cin >> a >> b;
    score[i] = {a,b};
  }
  sort(&score[0], &score[n], scoresort);
  int solved = score[4].first;
  for(int i = 5; i < n; i++){
    if(score[i].first != solved) break;
    ans++;
  }
  cout << ans;
  return 0;
}