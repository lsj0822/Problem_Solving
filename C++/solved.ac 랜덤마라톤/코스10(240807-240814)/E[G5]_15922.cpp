#include<iostream>
#include<algorithm>
#define X first
#define Y second
using namespace std;
int n, ans = 0;
pair<int, int> aww[100005];
int main(){
	cin >> n;
	for (int i = 0; i < n; i++) cin >> aww[i].X >> aww[i].Y;
	int s = aww[0].X, e = aww[0].Y;
	for(int i = 1; i < n; i++){
		int l = aww[i].X, r = aww[i].Y;
		if(e <= l) {
			ans += e - s;
			s = l;
		}
		e = max(e, r);
	}
	ans += e - s;
	cout << ans;
}