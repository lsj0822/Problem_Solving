#include <iostream>
#include <stack>
#include <queue>
using namespace std;

string str;
stack<int> num;
int main(void)
{
  ios::sync_with_stdio(0); cin.tie(0);
  getline(cin, str);
  for(auto c : str){
    if(c >= '0') num.push(c - '0');
    else{
      int l = num.top(); num.pop();
      int r = num.top(); num.pop();
      switch(c){
        case '+':
        num.push(r+l);
        break;
        case '-':
        num.push(r-l);
        break;
        case '*':
        num.push(r*l);
        break;
        case '/':
        num.push(r/l);
        break;
      }
    }
  }
  cout << num.top();
  return 0;
}