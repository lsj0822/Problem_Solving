#include <iostream>
#include <string>
using namespace std;

int n, m;
string str[105];
int main(void)
{
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    cin >> str[i];
  }
  
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      switch((int)(str[j][m-1-i])){
        case 45:
          cout << '|';
          break;
          case 46:
          cout << '.';
          break;
         case 47:
          cout << '\\';
          break;
          case 60:
          cout << 'v';
          break;
          case 62:
          cout << '^';
          break;
          case 79:
          cout << 'O';
          break;
          case 92:
          cout << '/';
          break;
          case 94:
          cout << '<';
          break;
          case 118:
          cout << '>';
          break;
          case 124:
          cout << '-';
          break;
        }
      }
  cout << '\n';
  }
  return 0;
}