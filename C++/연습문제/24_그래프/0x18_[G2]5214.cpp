#include <bits/stdc++.h>
using namespace std;
vector<int> linked[101005];
int dist[101005], tmp[1005], n, k, m;
queue<int> Q;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	fill(&dist[0], &dist[101001], 0);
	cin >> n >> k >> m;
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < k; j++) {
			int s;
			cin >> s;
			tmp[j] = s;
		}
		for (int j = 0; j < k; j++) {
			linked[i + 100000].push_back(tmp[j]);
			linked[tmp[j]].push_back(i + 100000);
		}
	}
	Q.push(1);
	dist[1] = 1;
	while (!Q.empty()) {
		int cur = Q.front(); Q.pop();
		if (cur == n) {
			cout << dist[cur];
			return 0;
		}
		for (int c : linked[cur]) {
			if (dist[c] != 0) continue;
			dist[c] = dist[cur];
			if (c <= 100000) dist[c]++;
			Q.push(c);
		}
	}
	cout << -1;
}