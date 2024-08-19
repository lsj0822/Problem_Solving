#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int sq[100005], n, m, r, idx = 1;
bool vst[100005];
vector<int> node[100005];
queue<int> Q;
int main() {
	cin >> n >> m >> r;
	while (m--) {
		int u, v;
		cin >> u >> v;
		node[u].push_back(v); node[v].push_back(u);
	}
	Q.push(r); vst[r] = 1;
	while (!Q.empty()) {
		int cur = Q.front(); Q.pop();
		sq[cur] = idx++;
		sort(node[cur].begin(), node[cur].end());
		for (int v : node[cur]) {
			if (vst[v] != 0) continue;
			vst[v] = 1;
			Q.push(v);
		}
	}
	for (int i = 1; i <= n; i++) cout << sq[i] << '\n';
}