#include<bits/stdc++.h>
using namespace std;
int v, m, e = 0, cnt = 0;
double ans = 0;
tuple<double, int, int> edge[1000005];
pair<int, int> pos[1005];
bool connected[1005][1005];
vector<int> g(1005, -1);
int find(int x) {
	if (g[x] < 0) return x;
	return g[x] = find(g[x]);
}
bool is_diff_group(int u, int v) {
	u = find(u); v = find(v);
	if (u == v) return 0;
	if (g[u] == g[v]) g[u]--;
	if (g[u] < g[v]) g[v] = u;
	else g[u] = v;
	return 1;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> v >> m;
	for (int i = 1; i <= v; i++) cin >> pos[i].first >> pos[i].second;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		connected[max(a, b)][min(a, b)] = 1;
	}
	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			if (i <= j) continue;
			double dx = pos[i].first - pos[j].first, dy = pos[i].second - pos[j].second, dist = pow(dx, 2) + pow(dy, 2);
			dist = sqrt(dist);
			if (connected[i][j]) dist = 0;
			edge[e++] = { dist,i,j };
		}
	}
	sort(&edge[0], &edge[e]);
	for (int i = 0; i < e; i++) {
		int a, b;
		double dist;
		tie(dist, a, b) = edge[i];
		if (!is_diff_group(a, b)) continue;
		cnt++;
		ans += dist;
		if (cnt == v - 1) break;
	}
	cout << fixed;
	cout << setprecision(2) << ans;
}