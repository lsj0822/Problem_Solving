#include<bits/stdc++.h>
using namespace std;
vector<int> node[10005], wtime(10005), res(10005);
int deg[10005], n, ans = 0;
queue<int> Q;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> wtime[i] >> deg[i];
		if (deg[i] == 0) Q.push(i);
		res[i] = wtime[i];
		for (int j = 0; j < deg[i]; j++) {
			int k;
			cin >> k;
			node[k].push_back(i);
		}
	}
	while (!Q.empty()) {
		int cur = Q.front(); Q.pop();
		for (int v : node[cur]) {
			deg[v]--;
			res[v] = max(res[cur] + wtime[v], res[v]);
			if (deg[v] == 0) Q.push(v);
		}
	}
	for (int i = 1; i <= n; i++) ans = max(ans, res[i]);
	cout << ans;
}