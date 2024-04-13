#include <bits/stdc++.h>
using namespace std;
int n, m, ans = 0;
vector<int> fri[505];
vector<int> dist(505,-1);
queue<int> Q;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		fri[a].push_back(b);
		fri[b].push_back(a);
	}
	dist[1] = 0;
	Q.push(1);
	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		for (auto c : fri[cur]) {
			if (dist[c] != -1) continue;
			dist[c] = dist[cur] + 1;
			Q.push(c);
		}
	}
	for (int i = 2; i <= n; i++) {
		if (dist[i] != -1 && dist[i] <= 2) ans++;
 	}
	cout << ans;
}