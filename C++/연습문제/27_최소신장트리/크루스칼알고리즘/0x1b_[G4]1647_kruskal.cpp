#include<bits/stdc++.h>
using namespace std;
int v, e, cnt = 0, ans = 0;
tuple<int, int, int> edge[1000005];
vector<int> g(100005, -1);
int find(int x) {
	if (g[x] < 0) return x;
	return g[x] = find(g[x]);
}
bool is_diff_group(int u, int v) {
	u = find(u), v = find(v);
	if (u == v) return 0;
	if (g[u] == g[v]) g[u]--;
	if (g[u] < g[v]) g[v] = u;
	else g[u] = v;
	return 1;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edge[i] = { c,a,b };
	}
	sort(&edge[0], &edge[e]);
	for (int i = 0; i < e; i++) {
		if (v == 2) break;
		int c, a, b;
		tie(c, a, b) = edge[i];
		if (!is_diff_group(a, b)) continue;
		cnt++;
		ans += c;
		if (cnt == v - 2) break;
	}
	cout << ans;
}