#include <bits/stdc++.h>
using namespace std;
map<string, vector<string>> name;
map<string, int> deg;
string memlist[1005];
vector<string> sijo;
int n, m;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		string str;
		cin >> str;
		vector<string> nullvec;
		name[str] = nullvec;
		deg[str] = 0;
		memlist[i] = str;
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		string u, v;
		cin >> u >> v;
		deg[u]++;
		name[v].push_back(u);
	}
	sort(&memlist[1], &memlist[n + 1]);
	for (int i = 1; i <= n; i++) {
		if (deg[memlist[i]] == 0) sijo.push_back(memlist[i]);
	}
	cout << sijo.size() << '\n';
	for (string v : sijo) cout << v << ' ';
	cout << '\n';
	for (int i = 1; i <= n; i++) {
		string mem = memlist[i];
		vector<string> js;
		cout << mem << ' ';
		for (string v : name[mem]) {
			if (deg[v] - deg[mem] == 1) js.push_back(v);
		}
		sort(js.begin(), js.end());
		cout << js.size() << ' ';
		for (string v : js) cout << v << ' ';
		cout << '\n';
	}
}