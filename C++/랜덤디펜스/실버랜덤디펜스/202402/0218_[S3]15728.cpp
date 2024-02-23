#include <iostream>
#include <algorithm>
using namespace std;

int n, k, team_card[105], share_card[105], result[105];
int main(void)
{
  cin >> n >> k;
  for(int i = 0; i < n; i++){
    cin >> share_card[i];
  }
    for(int i = 0; i < n; i++){
    cin >> team_card[i];
  }
  sort(&team_card[0], &team_card[n]);
  sort(&share_card[0], &share_card[n]);
  for(int i = 0; i < n; i++){
    if(team_card[i] < 0) result[i] = team_card[i] * share_card[0];
    else result[i] = team_card[i] * share_card[n-1];
  }
  sort(&result[0], &result[n]);
  cout << result[n-1-k];
  return 0;
}