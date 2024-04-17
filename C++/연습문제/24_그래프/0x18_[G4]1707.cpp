#include <bits/stdc++.h>
using namespace std;
int k, v, e;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> k;
	while (k--) {
		bool res = true;
		vector<int> node[20005], color(20005,0);
		queue<int> Q;
		cin >> v >> e;
		for (int i = 0; i < e; i++) {
			int a, b;
			cin >> a >> b;
			node[a].push_back(b);
			node[b].push_back(a);
		}
		for (int i = 1; i <= v; i++) {
			if (color[i] != 0) continue;
			if (!res) break;
			color[i] = 1;
			Q.push(i);
			while (!Q.empty()) {
				int cur = Q.front(); Q.pop();
				for (int c : node[cur]) {
					if (!res) break;
					if (color[c] != 0) {
						if (color[c] == color[cur]) {
							res = false;
							break;
						}
					}
					else {
						color[c] = 3 - color[cur];
						Q.push(c);
					}
				}
			}
		}
		if (res) cout << "YES";
		else cout << "NO";
		cout << '\n';
	}
}