#include <bits/stdc++.h>
using namespace std;

int n, arr[105][105], vst[105];
vector<int> graph[105];
queue<int> Q;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int k;
			cin >> k;
			if (k) graph[i].push_back(j);
		}
	}
	for (int i = 1; i <= n; i++) {
		memset(vst, 0, sizeof(vst));
		for (auto c : graph[i]) {
			arr[i][c] = 1;
			vst[c] = 1;
			Q.push(c);
		}
		while (!Q.empty()) {
			auto cur = Q.front(); Q.pop();
			for (auto c : graph[cur]) {
				if (vst[c]) continue;
				arr[i][c] = 1;
				vst[c] = 1;
				Q.push(c);
 			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
}