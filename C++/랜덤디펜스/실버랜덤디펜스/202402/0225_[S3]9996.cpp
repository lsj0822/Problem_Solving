#include <iostream>
#include <string>
using namespace std;

int n, ase;
string criteria;
int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> criteria;
  ase = criteria.find('*');
  for(int i = 0; i < n; i++){
    string str;
    cin >> str;
    if(str.length() < criteria.length() - 1){
      cout << "NE\n";
      continue;
    }
    if(str.substr(0,ase) == criteria.substr(0,ase) && str.substr(str.length()-criteria.length()+ase+1) == criteria.substr(ase+1)) cout << "DA\n";
    else cout << "NE\n";
  }
  return 0;
}