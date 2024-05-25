#include <bits/stdc++.h>
using namespace std;
const int INF = 100000;
int n, k, dist[15][15], ans = INF*100, vst[15];
void back_tracking(int dep, int cur, int total) {
	if (dep == n) {
		ans = min(ans, total);
		return;
	}
	for (int i = 0; i < n; i++) {
		if (i == cur) continue;
		if (vst[i]) continue;
		vst[i] = 1;
		back_tracking(dep + 1, i, total + dist[cur][i]);
		vst[i] = 0;
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> dist[i][j];
		}
	}
	for (int a = 0; a < n; a++) {
		for (int b = 0; b < n;b++) {
			for (int c = 0; c < n; c++) {
				dist[b][c] = min(dist[b][c], dist[b][a] + dist[a][c]);
			}
		}
	}
	vst[k] = 1;
	back_tracking(1, k, 0);
	cout << ans;
}