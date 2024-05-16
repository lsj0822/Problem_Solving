#include <bits/stdc++.h>
using namespace std;
int v, e, ans = 0, cnt = 0;
tuple<int, int, int> edge[100005];
vector<int> group(10005, -1);
int find(int x) {
	if (group[x] < 0) return x;
	return group[x] = find(group[x]);
}
bool is_diff_group(int u, int v) {
	u = find(u); v = find(v);
	if (u == v) return 0;
	if (group[u] == group[v]) group[u]--;
	if (group[u] < group[v]) group[v] = u;
	else group[u] = v;
	return 1;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		int cost, a, b;
		cin >> a >> b >> cost;
		edge[i] = { cost,a,b };
	}
	sort(&edge[0], &edge[e]);
	for (int i = 0; i < e; i++) {
		int cost, a, b;
		tie(cost, a, b) = edge[i];
		if (!is_diff_group(a,b)) continue;
		ans += cost;
		cnt++;
		if (cnt == v - 1) break;
	}
	cout << ans;
}