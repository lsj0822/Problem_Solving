#include <iostream>
#include <algorithm>

using namespace std;

int n, snow[605], ans = 1000000009;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> snow[i];
	sort(&snow[0], &snow[n]);
	for (int i = 0; i < n; i++) {
		for (int j = i + 3; j < n; j++) {
			int crit = snow[i] + snow[j], st = i+1, en = j-1;
			while(st < en) {
				if (st == i || st == j) {
					st++;
					continue;
				}
				if (en == i || en == j) {
					en--;
					continue;
				}
				int res = crit - snow[st] - snow[en];
				ans = min(abs(res), ans);
				if (res >= 0) st++;
				else en--;
			}
		}
	}
	cout << ans;
}