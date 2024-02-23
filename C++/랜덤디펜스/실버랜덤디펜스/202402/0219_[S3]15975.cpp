#include <iostream>
#include <algorithm>
#define X first
#define Y second
using namespace std;

int n, MX = 10e9 + 5;
long long ans = 0;
pair<int, int> point[100005];

bool point_sort(pair<int,int> a, pair<int,int> b){
  if(a.Y != b.Y) return a.Y < b.Y;
  return a.X < b.X;
}
int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++){
    int x, color;
    cin >> x >> color;
    point[i] = {x, color};
  }
  sort(&point[0], &point[n], point_sort);
  for(int i = 0; i < n; i++){
    int tmp = MX;
    if(i > 0 && point[i].Y == point[i-1].Y) tmp = point[i].X - point[i-1].X;
    if(i < n-1 && point[i].Y == point[i+1].Y) tmp = min(tmp, point[i+1].X - point[i].X);
    if(tmp < MX) ans += tmp;
  }
  cout << ans;
  return 0;
}