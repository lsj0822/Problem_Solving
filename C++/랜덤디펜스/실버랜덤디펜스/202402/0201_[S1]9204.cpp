#include <iostream>
using namespace std;

int t;
//BFS를 사용하지 않은 풀이. 무조건 2회 안으로 움직일 수 있다.
int main(void)
{
  cin >> t;
  while(t--){
    int y1, y2;
    char x1, x2;
    cin >> x1 >> y1 >> x2 >> y2;
    int sum1 = x1-'A' + y1, sum2 = x2 - 'A' + y2;
    int minus1 = x1 - 'A' - y1, minus2 = x2 - 'A' - y2;
    if(sum1 % 2 != sum2 %2) cout << "Impossible\n";
    else if(x1 == x2 && y1 == y2) cout << 0 << " " << x1 << " " << y1 << '\n';
    else if(sum1 == sum2 || minus1 == minus2){
      cout << 1 << " " << x1 << " " << y1 << " " << x2 << " " << y2 << '\n';
    }
    else{
      cout << 2 << " " << x1 << " " << y1 << " ";
      cout << static_cast<char>((sum1+minus2) / 2 + 'A') << " " << (sum1-minus2) / 2 << " ";
      cout << x2 << " " << y2 << '\n';
    }
  }
  return 0;
}