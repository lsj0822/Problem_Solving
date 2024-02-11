#include <bits/stdc++.h>

using namespace std;

int k = 1, n, path[100005][3], res[100005][3];
int main() {
	while (1) {
		cin >> n;
		if (!n) return 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 3; j++) {
				cin >> path[i][j];
			}
		}
		res[0][0] = 1001;
		res[0][1] = path[0][1];
		res[0][2] = path[0][1] + path[0][2];
		for (int i = 1; i < n; i++) {
			res[i][0] = min(res[i - 1][0], res[i - 1][1]) + path[i][0];
			res[i][1] = min({ res[i - 1][0], res[i - 1][1], res[i - 1][2], res[i][0] }) + path[i][1];
			res[i][2] = min({ res[i - 1][1], res[i - 1][2], res[i][1] }) + path[i][2];
		}
		cout << k << ". " << res[n - 1][1] << '\n';
		k++;
	}
}