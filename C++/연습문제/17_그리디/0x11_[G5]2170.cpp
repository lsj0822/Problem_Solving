#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
int n, s, e, ans = 0;
pair<int, int> line[1000005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		line[i] = { x, y };
	}
	sort(&line[0], &line[n]);
	s = line[0].X; e = line[0].Y;
	for (int i = 1; i < n; i++) {
		if (e <= line[i].X) {
			ans += e - s;
			s = line[i].X;
		}
		e = max(e,line[i].Y);
	}
	cout << ans + e - s;
}