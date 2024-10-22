#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;
const int SIZE = 1005, MOD = 1e9 + 7;
int n, q, arr[SIZE], arrsize[SIZE];
vector<int> adj[SIZE];
vector<long long> res(SIZE);
void BFS(int srt) {
	queue<int> Q;
	Q.push(srt);
	res[srt] = arr[srt];
	while (!Q.empty()) {
		int cur = Q.front(); Q.pop();
		for (int v : adj[cur]) {
			if (res[v] != -1) continue;
			long long conc = res[cur];
			for (int i = 0; i < arrsize[v]; i++) conc = (conc * 10) % MOD;
			res[v] = (conc + arr[v]) % MOD;
			Q.push(v);
		}
	}
}
int main() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	for (int i = 1; i <= n; i++) arrsize[i] = to_string(arr[i]).length();
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	while (q--) {
		fill(res.begin(), res.end(), -1);
		int u, v;
		cin >> u >> v;
		BFS(u);
		cout << res[v] << '\n';
	}
}