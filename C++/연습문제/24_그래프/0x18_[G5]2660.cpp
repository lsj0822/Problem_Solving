#include <bits/stdc++.h>
using namespace std;
int n, dist[55], result;
vector<int> f_list[55], score[55];
queue<int> Q;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	while (1) {
		int a, b;
		cin >> a >> b;
		if (a == -1 && b == -1) break;
		f_list[a].push_back(b);
		f_list[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		result = 0;
		fill(&dist[0], &dist[51], -1);
		dist[i] = 0;
		Q.push(i);
		while (!Q.empty()) {
			int cur = Q.front(); Q.pop();
			for (int c : f_list[cur]) {
				if (dist[c] != -1) continue;
				Q.push(c);
				dist[c] = dist[cur] + 1;
				result = max(result, dist[c]);
			}
		}
		score[result].push_back(i);
	}
	for (int i = 1; i <= 50; i++) {
		if (score[i].empty()) continue;
		cout << i << ' ' << score[i].size() << '\n';
		for (int r : score[i]) cout << r << ' ';
		return 0;
	}
}