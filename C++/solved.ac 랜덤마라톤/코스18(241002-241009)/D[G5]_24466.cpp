#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
using namespace std;
int n, m;
vector<pair<int, long long>> adj[105];
vector<int> ans;
long long dp[10][105];
int main() {
	cin >> n >> m;
	while (m--) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ v,w });
	}
	dp[0][0] = 1;
	for (int d = 1; d <= 9; d++) {
		for (int i = 0; i < n; i++) {
			for (auto v : adj[i]) {
				dp[d][v.first] += v.second * dp[d - 1][i];
			}
		}
	}
	long long maxpossi = 0;
	for (int i = 0; i < n; i++) {
		if (dp[9][i] > maxpossi) {
			ans.clear();
			maxpossi = dp[9][i];
			ans.push_back(i);
		}
		else if (dp[9][i] == maxpossi) {
			ans.push_back(i);
		}
	}
	for (int v : ans) cout << v << ' ';
	cout << '\n';
	if (maxpossi == 1e18) cout << "1.000000000000000000";
	else {
		cout << "0.";
		cout << setw(18) << setfill('0') << to_string(maxpossi);
	}
}