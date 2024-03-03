#include <iostream>
#include <vector>
using namespace std;

int n, m, ans = 7, idx = 0; 
vector<bool> paper(105);
vector<int> empty_paper;
int main(void)
{
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < m; i++){
    int k;
    cin >> k;
    paper[k] = 1;
  }
  for(int i  = 1; i <= n; i++){
    if(!paper[i]) empty_paper.push_back(i);
  }
  int p_size = empty_paper.size();
  if(p_size == 0){
    cout << 0;
    return 0;
  }
  for(int i = 1; i < p_size; i++){
    ans += min(7, (empty_paper[i] - empty_paper[i-1])*2);
  }
  cout << ans;
  return 0;
}