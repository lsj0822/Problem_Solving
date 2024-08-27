#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
string str, ans = "";
vector<int> node[500005];
vector<bool> vst(500005);
int n;
void BFS() {
	queue<int> Q, tmp;
	Q.push(1);
	vst[1] = 1;
	ans += str[0];
	while (!Q.empty()) {
		char cmax = 'Z';
		while (!Q.empty()) {
			int cur = Q.front(); Q.pop();
			for (int v : node[cur]) {
				if (vst[v]) continue;
				vst[v] = 1;
				if (cmax <= str[v - 1]) {
					cmax = str[v - 1];
					tmp.push(v);
				}
			}
		}
		if (cmax >= 'a') ans += cmax;
		while (!tmp.empty()) {
			int cur = tmp.front(); tmp.pop();
			if (str[cur - 1] == cmax) Q.push(cur);
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> str;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		node[u].push_back(v);
		node[v].push_back(u);
	}
	BFS();
	cout << ans;
}