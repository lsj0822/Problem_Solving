#include <iostream>
#include <string>
using namespace std;

int n;
string str[105];
int main(void)
{
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> str[i];
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(str[i][j] != str[j][i]){
        cout << "NO";
        return 0;
      }
    }
  }
  cout << "YES";
  return 0;
}