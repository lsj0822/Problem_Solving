#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int vst[1000005];
int N, a, b;
queue<int> Q;

int main(void)
{
  fill(&vst[0], &vst[1000000], -1);
  cin >> N >> a >> b;
  vst[N] = 0;
  Q.push(N);
  while(!Q.empty()){
    int num = Q.front(); Q.pop();
    for(int i : {num-1, num-1-a, num-1-b}){
      if(i<0 || vst[i] != -1) continue;
      vst[i] = vst[num] + 1;
      Q.push(i);
    }
  }
  cout << vst[0];
}