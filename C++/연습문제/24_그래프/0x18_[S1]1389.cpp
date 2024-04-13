#include <bits/stdc++.h>
using namespace std;
int n, m, dist[105];
pair<int, int> inssa = { 0, 99999 };
vector<int> fri[105];
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
	for (int i = 1; i <= n; i++) {
		int result = 0;
		fill(&dist[0], &dist[101], -1);
		dist[i] = 0;
		Q.push(i);
		while (!Q.empty()) {
			int cur = Q.front(); Q.pop();
			for (int c : fri[cur]) {
				if (dist[c] != -1) continue;
				dist[c] = dist[cur] + 1;
				Q.push(c);
			}
		}
		for (int i = 1; i <= n; i++) result += dist[i];
		if (result < inssa.second) inssa = { i, result };
	}
	cout << inssa.first;
}