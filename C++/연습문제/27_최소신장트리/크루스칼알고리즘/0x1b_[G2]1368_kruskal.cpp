#include <bits/stdc++.h>
using namespace std;
int v, e = 0, ans = 0, cnt = 0;
tuple<int, int, int> edge[100005];
vector<int> g(10005, -1);
int find(int x) {
	if (g[x] < 0) return x;
	return g[x] = find(g[x]);
}
bool is_diff_group(int u, int v) {
	u = find(u); v = find(v);
	if (u == v) return 0;
	if (g[u] == g[v]) g[u]--;
	if (g[u] < g[u]) g[v] = u;
	else g[u] = v;
	return 1;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> v;
	for (int i = 1; i <= v; i++) {
		int cost;
		cin >> cost;
		edge[e++] = { cost, i, v+1};
	}
	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			int cost;
			cin >> cost;
			if (j >= i) continue;
			edge[e++] = { cost,i,j };
		}
	}
	sort(&edge[0], &edge[e]);
	for (int i = 0; i < e; i++) {
		int cost, a, b;
		tie(cost, a, b) = edge[i];
		if (!is_diff_group(a, b)) continue;
		ans += cost;
		cnt++;
		if (cnt == v) break;
	}
	cout << ans;
}