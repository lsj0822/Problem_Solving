#include <iostream>
using namespace std;

int score[50], ans = 0;
int main(void)
{
  for(int i = 0; i < 50; i++){
    cin >> score[i];
  }
  int hong;
  cin >> hong;
  while(true){
    if(score[ans] == hong) break;
    ans++;
  }
  switch(ans/5){
    case 0:
    cout << "A+";
    break;
    case 1:
    case 2:
    cout << "A0";
    break;
    case 3:
    case 4:
    case 5:
    cout << "B+";
    break;
    case 6:
    cout << "B0";
    break;
    case 7:
    case 8:
    cout << "C+";
    break;
    case 9:
    if(ans <= 47) cout << "C0";
    else cout << "F";
    break;
  }
  return 0;
}