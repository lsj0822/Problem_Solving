#include <bits/stdc++.h>
using namespace std;
int n, m, ans = 0;
vector<int> graph[1005];
vector<bool> vst(1005, 0);
queue<int> Q;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		if (vst[i]) continue;
		Q.push(i);
		vst[i] = 1;
		while (!Q.empty()) {
			auto cur = Q.front(); Q.pop();
			for (auto c : graph[cur]) {
				if (vst[c]) continue;
				vst[c] = 1;
				Q.push(c);
			}
		}
		ans++;
	}
	cout << ans;
}