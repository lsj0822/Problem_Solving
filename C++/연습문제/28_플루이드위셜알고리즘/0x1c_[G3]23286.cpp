#include<bits/stdc++.h>
using namespace std;
const int INF = 1000005;
int n, m, t, height[305][305];
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	fill(&height[0][0], &height[301][0], INF);
	cin >> n >> m >> t;
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		height[a][b] = min(height[a][b], c);
	}
	for (int i = 1; i <= n; i++) height[i][i] = 0;
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				height[i][j] = min(height[i][j], max(height[i][k], height[k][j]));
			}
		}
	}
	while (t--) {
		int a, b;
		cin >> a >> b;
		cout << ((height[a][b]==INF)?-1:height[a][b]) << '\n';
	}
}