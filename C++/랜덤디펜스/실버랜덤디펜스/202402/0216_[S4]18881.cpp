#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int n, SD = 1000005, ans = 1, sickcow[1005], idx = 0;
pair<int, int> cow[1005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> cow[i].X >> cow[i].Y;
		if (cow[i].Y) sickcow[idx++] = cow[i].X;
	}
	sort(&cow[0], &cow[n]);
	sort(&sickcow[0], &sickcow[idx]);
	for (int i = 1; i < n; i++) {
		if (cow[i].Y != cow[i - 1].Y) SD = min(SD, cow[i].X - cow[i - 1].X);
	}
	for (int i = 1; i < idx; i++) {
		if (sickcow[i] - sickcow[i - 1] >= SD) ans++;
	}
	cout << ans;
}
