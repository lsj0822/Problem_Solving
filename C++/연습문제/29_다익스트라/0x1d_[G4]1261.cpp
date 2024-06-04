#include<bits/stdc++.h>
using namespace std;
const int INF = 1000;
int n, m, dist[10005];
int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
string board[105];
vector<pair<int, int>> node[10005];
priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	fill(&dist[0], &dist[10005], INF);
	cin >> m >> n;
	for (int i = 0; i < n; i++) cin >> board[i];
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < m; y++) {
			int pos = x * 100 + y;
			for (int dir = 0; dir < 4; dir++) {
				int nx = x + dx[dir], ny = y + dy[dir];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				node[pos].push_back({ board[nx][ny] - '0',nx * 100 + ny });
			}
		}
	}
	dist[0] = 0;
	pq.push({ 0,0 });
	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		if (cur.first != dist[cur.second]) continue;
		for (auto nxt : node[cur.second]) {
			int w = cur.first + nxt.first;
			if (w >= dist[nxt.second]) continue;
			dist[nxt.second] = w;
			pq.push({ w, nxt.second });
		}
	}
	cout << dist[(n - 1) * 100 + m - 1];
}