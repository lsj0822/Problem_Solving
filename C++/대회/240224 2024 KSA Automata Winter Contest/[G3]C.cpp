#include <bits/stdc++.h>

using namespace std;

int n, k, ans = -1, carrot[105][5500], active[5500], mp = 1;
pair<int, int> speed[105];
bool speed_compare(pair<int, int> a, pair<int, int> b) {
	if (a.first != b.first) return a.first < b.first;
	else return a.second > b.second;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		speed[i] = { a,b };
	}
	sort(&speed[0], &speed[n], speed_compare);
	carrot[1][1] = 1;
	active[1] = 1;
	for (int i = 2; i <= k; i++) {
		for (int p = 1; p <= mp; p++) {
			if (active[p]) carrot[i][p] = carrot[i - 1][p] + p;
		}
		for(int p = 1; p <= mp; p++){
			for (int s = 0; s < n; s++) {
				if (speed[s].first <= carrot[i - 1][p]) {
					carrot[i][p + speed[s].second] = max(carrot[i][p + speed[s].second], carrot[i - 1][p] - speed[s].first);
					active[p + speed[s].second] = 1;
					mp = max(mp, p + speed[s].second);
				}
				else break;
			}
		}
	}

	for (int i = 1; i <= mp; i++) {
		ans = max(ans, carrot[k][i]);
	}
	cout << ans;
}