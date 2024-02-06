#include <bits/stdc++.h>

using namespace std;

int n, cost[1005][3], res[1005][3];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> cost[i][j];
		}
	}
	for (int i = 0; i < 3; i++) {
		res[0][i] = cost[0][i];
	}
	for (int i = 1; i < n; i++) {
		res[i][0] = min(res[i - 1][1], res[i - 1][2]) + cost[i][0];
		res[i][1] = min(res[i - 1][0], res[i - 1][2]) + cost[i][1];
		res[i][2] = min(res[i - 1][0], res[i - 1][1]) + cost[i][2];
	}
	cout << min({ res[n - 1][0],res[n - 1][1],res[n - 1][2] });
}