#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, divnum = 2, divcnt = 0;
		cin >> n;
		queue<pair<int, int>> Q;
		while (n != 1) {
			if (n % divnum == 0) {
				divcnt++;
				n /= divnum;
			}
			else {
				if (divcnt) {
					Q.push({ divnum,divcnt });
					divcnt = 0;
				}
				divnum++;
			}
		}
		Q.push({ divnum,divcnt });
		while (!Q.empty()) {
			auto cur = Q.front(); Q.pop();
			cout << cur.first << ' ' << cur.second << '\n';
		}
	}
}