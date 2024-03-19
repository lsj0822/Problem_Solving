#include <iostream>
#include <vector>
using namespace std;

int n, board[2000005], x, onenum = 0;
vector<int> one;
int main(void)
{
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for(int i = 0; i <= n; i++){
    cin >> board[i];
    if(board[i] == 1){
      onenum++;
      one.push_back(i);
    }
  }
  cin >> x;
  //case 1 : 1이 3개 이상 -> 무조건 불가능
  //case 2 : 1이 2개 -> 두개가 서로 상쇄되지 않는 이상 불가능
  //case 3 : 1이 1개 -> 1을 x칸전이 상쇄하되, 이때 x칸전의 말의 개수는 2개 초과여야함
  //case 4 : 1이 0개 -> 3개 이상인 말이 있는 곳에서 이동한 칸에 말이 1 이상일 때만 성립
  if(onenum > 2){ //case1
    cout << "NO";
  }
  else if(onenum == 2){ //case2
    if(one[1] - one[0] == x) cout << "YES" << '\n' << one[0] << ' ' << one[1];
    else cout << "NO";
  }
  else if(onenum == 1){ //case3
    if((one[0]-x >= 0) && (board[one[0]-x] > 2)) cout << "YES" << '\n' << one[0]-x << ' ' << one[0];
    else if((one[0]+x <= n) && (board[one[0]+x] >= 2)) cout << "YES" << '\n' << one[0] << ' ' << one[0]+x;
    else cout << "NO";
  }
  else{ //case4
    bool pass = false;
    for(int i = 0; i <= n; i++){
      if(board[i] > 2){
        if((i+x <= n) && (board[i+x] >= 2)){
          pass = true;
          cout << "YES" << '\n' << i << ' ' << i+x;
          break;
        } 
      }
    }
    if(!pass) cout << "NO";
  }
  return 0;
}