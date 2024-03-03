#include <iostream>
#include <string>
using namespace std;

int n, shortcut[27];
string str[35];
int main(void)
{
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for(int i = 0; i <= n; i++) getline(cin, str[i]);
  for(int i = 1; i <= n; i++){
    bool is_shortcut = false;
    int scidx;
    for(int c = 0; c < str[i].length(); c++){
      if(c == 0 || str[i][c-1] == ' ' && str[i][c] != ' '){
        if(shortcut[tolower(str[i][c])-'a'] == 0){
          is_shortcut = true;
          shortcut[tolower(str[i][c])-'a'] = 1;
          scidx  = c;
          break;
        }
      }
    }
    if(!is_shortcut){
      for(int c = 0; c < str[i].length(); c++){
          if(str[i][c] != ' ' && shortcut[tolower(str[i][c])-'a'] == 0){
          is_shortcut = true;
          shortcut[tolower(str[i][c])-'a'] = 1;
          scidx  = c;
          break;
        }
      }
    }
    if(is_shortcut){
      for(int c = 0; c < str[i].length(); c++){
        if(c == scidx) cout << '[' << str[i][c] << ']';
        else cout << str[i][c];
      }
    }
    else cout << str[i];
    cout << '\n';
  }
  return 0;
}