#include<bits/stdc++.h>
using namespace std;
tuple<int, int, int> edge[1000005];
int v, e, cnt = 0, ans[2] = {0,};
vector<int> g(1005, -1);
bool reverse_sort(tuple<int, int, int> a, tuple<int, int, int> b) {
	return get<0>(a) > get<0>(b);
}
int find(int x) {
	if (g[x] < 0) return x;
	else return g[x] = find(g[x]);
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
	cin >> v >> e;
	for (int i = 0; i <= e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edge[i] = { c,a,b };
	}
	sort(&edge[0], &edge[e+1]);
	for (int i = 0; i <= e; i++) {
		int a, b, c;
		tie(c, a, b) = edge[i];
		if (!is_diff_group(a, b))continue;
		cnt++;
		ans[0] += 1-c;
		if (cnt == v) break;
	}
	sort(&edge[0], &edge[e+1], reverse_sort);
	fill(g.begin(), g.end(), -1);
	cnt = 0;
	for (int i = 0; i <= e; i++) {
		int a, b, c;
		tie(c, a, b) = edge[i];
		if (!is_diff_group(a, b))continue;
		cnt++;
		ans[1] += 1-c;
		if (cnt == v) break;
	}
	cout << ans[0]*ans[0] - ans[1]*ans[1];
}