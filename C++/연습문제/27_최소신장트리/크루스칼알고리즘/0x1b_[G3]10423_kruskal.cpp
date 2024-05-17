#include<bits/stdc++.h>
using namespace std;
int v, e, k, ans = 0, cnt = 0, plant[1005];
tuple<int, int, int> edge[105005];
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
	cin >> v >> e >> k;
	for (int i = 0; i < k; i++) cin >> plant[i];
	for (int i = 0; i < e; i++) {
		int a,b, w;
		cin >> a >> b >> w;
		edge[i] = { w,a,b };
	}
	for (int i = 0; i < k; i++) edge[e++] = { 0,0,plant[i] };
	sort(&edge[0], &edge[e]);
	for (int i = 0; i < e; i++) {
		int w, a, b;
		tie(w, a, b) = edge[i];
		if (!is_diff_group(a, b)) continue;
		ans += w;
		cnt++;
		if (cnt == v) break;
	}
	cout << ans;
}