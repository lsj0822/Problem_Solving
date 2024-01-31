#include <iostream>
#include <string>
#include <vector>
using namespace std;
int t;
bool check_AFC(vector<pair<int,char>> V, int A, int F, int C){
  return V[A].second = 'A' && V[F].second == 'F' && V[C].second == 'C';
}
int main(void)
{
  cin >> t;
  while(t--){
    vector<pair<int,char>> V;
    bool flag = false;
    string str;
    cin >> str;
    for(int i = 1; i < str.length(); i++){
      if(str[i] != str[i-1]){
        V.push_back({i-1,str[i-1]});
      }
    }
    V.push_back({str.length()-1,str[str.length()-1]});
    if (V.size() == 3 && check_AFC(V,0,1,2)) flag = true;
    if(V.size() == 4 && V[0].second <= 'F' && check_AFC(V,1,2,3)) flag = true;
    if(V.size() == 5 && V[0].second <= 'F' && V[4].second <= 'F' && check_AFC(V,1,2,3)) flag = true;
    if(flag) cout << "Infected!";
    else cout << "Good";
    cout << '\n';
    
  }
  return 0;
}