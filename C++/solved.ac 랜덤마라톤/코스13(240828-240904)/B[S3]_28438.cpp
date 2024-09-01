#include<iostream>
#include<vector>
using namespace std;
int n, m, q;
int main() {
	cin >> n >> m >> q;
	vector<int> rowval(n), colval(m);
	while (q--) {
		int t, u, v;
		cin >> t >> u >> v;
		switch (t) {
		case 1:
			rowval[u - 1] += v;
			break;
		case 2:
			colval[u - 1] += v;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << rowval[i] + colval[j] << ' ';
		}
		cout << '\n';
	}
}