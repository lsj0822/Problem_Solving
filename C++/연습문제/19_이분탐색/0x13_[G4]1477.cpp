#include <bits/stdc++.h>

using namespace std;

int n, m, l, st, en, mid, ans = 1005;
vector<int> station;
int main() {
	cin >> n >> m >> l;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		station.push_back(k);
	}
	station.push_back(0); station.push_back(l);
	sort(station.begin(), station.end());
	st = 1; en = l-1;
	while (st <= en) {
		mid = (st + en) / 2;
		int inst = 0;
		for (int i = 1; i < station.size(); i++) {
			int dist = station[i] - station[i - 1];
			inst += dist/mid;
			if (!(dist % mid)) inst--;
		}
		if (inst > m) st = mid + 1;
		else {
			en = mid - 1;
			ans = min(ans, mid);
		}
	}
	cout << ans;
}