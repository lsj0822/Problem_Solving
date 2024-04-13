#include<bits/stdc++.h>
using namespace std;
int n, m, max_length = -1, dist[20005];
vector<int> result[20005], connect[20005];
queue<int> Q;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	fill(&dist[0], &dist[20001], -1);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		connect[a].push_back(b);
		connect[b].push_back(a);
	}
	Q.push(1);
	dist[1] = 0;
	while (!Q.empty()) {
		int cur = Q.front(); Q.pop();
		for (int c : connect[cur]) {
			if (dist[c] != -1) continue;
			dist[c] = dist[cur] + 1;
			result[dist[c]].push_back(c);
			max_length = max(max_length, dist[c]);
			Q.push(c);
		}
	}
	sort(result[max_length].begin(), result[max_length].end());
	cout << result[max_length][0] << ' ' << max_length << ' ' << result[max_length].size();
}