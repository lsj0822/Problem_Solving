#include<iostream>
#include<vector>
#include<iostream>
#include<queue>
using namespace std;
int n, m, q, k, day[100005];
vector<int> adj[100005], res;
queue<int> Q;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> q >> k;
	fill(&day[0], &day[n + 1], -1);
	while(q--){
		int a;
		cin >> a;
		day[a] = 0;
		Q.push(a);
	}
	while (m--) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	while (!Q.empty()) {
		int cur = Q.front(); Q.pop();
		for (int nxt : adj[cur]) {
			if (day[nxt] != -1) continue;
			day[nxt] = day[cur] + 1;
			Q.push(nxt);
		}
	}
	for (int i = 0; k * i *(i + 1) / 2 <= n; i++) res.push_back(k * i * (i + 1) / 2);
	for (int i = 1; i <= n; i++) cout << lower_bound(res.begin(), res.end(), day[i])-res.begin() << ' ';
}