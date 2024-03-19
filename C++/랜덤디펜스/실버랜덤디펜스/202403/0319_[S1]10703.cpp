#include <iostream>
#include <algorithm>
using namespace std;

char sate[3005][3005];
int r, s, diff = 3005;
int main(void)
{
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> r >> s;
  for(int i = 0; i < r; i++){
    for(int j = 0; j < s; j++){
      cin >> sate[i][j];
    }
  }
    for(int i = 0; i < s; i++){
      int land = 3005, star = -1;
      for(int j = 0; j < r; j++){
        if(sate[j][i] == 'X') star = max(star, j);
        if(sate[j][i] == '#') land = min(land, j);
      }
      if(land == 3005 || star == -1) continue;
      diff = min(diff, land - star-1);
    }
    for(int i = r-1; i >= 0; i--){
      for(int j = 0; j < s; j++){
        if(sate[i][j] == 'X') swap(sate[i+diff][j], sate[i][j]);
      }
    }
    for(int i = 0; i < r; i++){
      for(int j = 0; j < s; j++){
        cout << sate[i][j];
      }
      cout << '\n';
    }
  }