#include<iostream>
#define X first
#define Y second
using namespace std;
int n, r, minx = 101, maxx = -101, miny = 101, maxy = -101, maxcnt = -1;
pair<int, int> ans, bab[101];
int main() {
	cin >> n >> r;
	r *= r;
	for (int i = 0; i < n; i++) {
		cin >> bab[i].X >> bab[i].Y;
		minx = min(minx, bab[i].X); miny = min(miny, bab[i].Y);
		maxx = max(maxx, bab[i].X); maxy = max(maxy, bab[i].Y);
	}
	for (int i = minx; i <= maxx; i++) {
		for (int j = miny; j <= maxy; j++) {
			int tmp = 0;
			for (int k = 0; k < n; k++) {
				int d = (bab[k].X - i) * (bab[k].X - i) + (bab[k].Y - j) * (bab[k].Y - j);
				if (d <= r) tmp++;
			}
			if (tmp > maxcnt) {
				maxcnt = tmp;
				ans = { i,j };
			}
		}
	}
	cout << ans.X << ' ' << ans.Y;
}