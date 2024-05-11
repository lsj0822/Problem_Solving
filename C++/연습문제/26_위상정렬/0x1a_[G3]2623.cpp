#include<bits/stdc++.h>
using namespace std;
int n, m, deg[1005];
vector<int> node[1005], result;
queue<int> Q;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int l, arr[1005];
		cin >> l;
		for (int k = 0; k < l; k++) cin >> arr[k];
		for (int k = 0; k < l - 1; k++) {
			deg[arr[k + 1]]++;
			node[arr[k]].push_back(arr[k + 1]);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (deg[i] == 0) Q.push(i);
	}
	while (!Q.empty()) {
		int cur = Q.front(); Q.pop();
		result.push_back(cur);
		for (int v : node[cur]) {
			deg[v]--;
			if (deg[v] == 0) Q.push(v);
		}
	}
	if (result.size() != n) cout << 0;
	else for (int v : result) cout << v << '\n';
}