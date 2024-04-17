#include <bits/stdc++.h>
using namespace std;
vector<int> guest[55];
set<int> seen[55];
vector<bool> know(55, 0);
queue<int> Q;
int n, m, k, ans = 0;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		int p;
		cin >> p;
		know[p] = 1;
		Q.push(p);
	}
	for (int i = 0; i < m; i++) {
		cin >> k;
		for (int j = 0; j < k; j++) {
			int p;
			cin >> p;
			guest[i].push_back(p);
		}
	}
	for (int i = 0; i < m; i++) {
		int g = guest[i].size();
		for (int a = 0; a < g; a++) {
			for (int b = a + 1; b < g; b++) {
				seen[guest[i][a]].insert(guest[i][b]);
				seen[guest[i][b]].insert(guest[i][a]);
			}
		}
	}
	while (!Q.empty()) {
		int cur = Q.front(); Q.pop();
		for (int c : seen[cur]) {
			if (know[c]) continue;
			know[c] = 1;
			Q.push(c);
		}
	}
	for (int i = 0; i < m; i++) {
		bool res = 0;
		for (int c : guest[i]) {
			if (know[c] == 1) {
				res = 1;
				break;
			}
		}
		if (!res) ans++;
	}
	cout << ans;
}