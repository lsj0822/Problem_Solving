#include <bits/stdc++.h>
using namespace std;

int n, m;
int path[100002];

int main() {
	cin >> n >> m;
	queue<int> Q;
	fill(path, path + 100001, -1);
	path[n] = 0;
	Q.push(n);
	while (!Q.empty()) {
		int cur = Q.front(); Q.pop();
		for (int nxt : {cur + 1, cur - 1, cur * 2}) {
			if (nxt < 0 || nxt > 100000) continue;
			if (path[nxt] != -1) continue;
			if (nxt == m) {
				cout << path[cur] + 1;
				return 0;
			}
			path[nxt] = path[cur] + 1;
			Q.push(nxt);
		}
	}
	cout << 0; //n == m
}