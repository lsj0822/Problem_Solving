#include <iostream>
#include <string>
using namespace std;

int n, m, len, underbar[12];
string str[12];
char letter[12];
int main(void)
{
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    cin >> str[i];
    letter[i] = str[i][0];
    len += str[i].length();
  }
  int left = m - len, gap = left/(n-1);
  for(int i = 0; i < n-1; i++){
    underbar[i] = gap;
  }
  left = left%(n-1);
  for(int i = 1; i < n; i++){
    if(letter[i] >= 'a' && left > 0){
      underbar[i-1]++;
      left--;
    }
  }
  if(left > 0){
    for(int i = n-2; i >= 0; i--){
      if(underbar[i] == gap && left > 0){
        underbar[i]++;
        left--;
      }
    }
  }
  for(int i = 0; i < n-1; i++){
    cout << str[i];
    for(int j = 0; j < underbar[i]; j++) cout << '_';
  }
  cout << str[n-1];
  return 0;
}