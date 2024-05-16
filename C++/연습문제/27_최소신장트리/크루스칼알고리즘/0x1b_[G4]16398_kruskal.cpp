#include<bits/stdc++.h>
using namespace std;
int n, e = 0, cnt = 0;
long long ans = 0;
tuple<int, int, int> edge[1000000];
vector<int> g(10005, -1);
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
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int c;
			cin >> c;
			if (i <= j) continue;
			edge[e++] = { c,i,j };
		}
	}
	sort(&edge[0], &edge[e]);
	for (int i = 0; i < e; i++) {
		int c, a, b;
		tie(c, a, b) = edge[i];
		if (!is_diff_group(a, b)) continue;
		ans += c;
		cnt++;
		if (cnt == n-1) break;
	}
	cout << ans;
}