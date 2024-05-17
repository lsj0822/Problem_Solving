#include<bits/stdc++.h>
using namespace std;
int v, m, cnt = 0;
double ans = 0;
vector<pair<double, int>> adj[1005];
pair<int, int> pos[1005];
priority_queue<tuple<double, int, int>, vector<tuple<double, int, int>>, greater<tuple<double, int, int>>> pq;
bool connected[1005][1005], vst[1005];
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> v >> m;
	for (int i = 1; i <= v; i++) cin >> pos[i].first >> pos[i].second;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		connected[min(a, b)][max(a, b)] = 1;
	}
	for (int i = 1; i <= v; i++) {
		for (int j = i + 1; j <= v; j++) {
			int dx = pos[i].first - pos[j].first, dy = pos[i].second - pos[j].second;
			double dist = pow(dx, 2) + pow(dy, 2);
			dist = sqrt(dist);
			if (connected[i][j]) dist = 0;
			adj[i].push_back({ dist,j });
			adj[j].push_back({ dist,i });
		}
	}
	vst[1] = 1;
	for (auto nxt : adj[1]) pq.push({ nxt.first, 1, nxt.second });
	while (cnt < v - 1) {
		auto cur = pq.top(); pq.pop();
		double dist; int a, b;
		tie(dist, a, b) = cur;
		if (vst[b]) continue;
		vst[b] = 1;
		cnt++;
		ans += dist;
		for (auto nxt : adj[b]) if (!vst[nxt.second]) pq.push({ nxt.first, b, nxt.second });
	}
	cout << fixed << setprecision(2) << ans;
}