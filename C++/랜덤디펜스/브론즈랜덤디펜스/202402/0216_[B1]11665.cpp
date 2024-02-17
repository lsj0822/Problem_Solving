#include <bits/stdc++.h>

using namespace std;

int n, cube[6], ans = 1;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	fill(&cube[3], &cube[6], 1001);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			int k;
			cin >> k;
			cube[j] = max(cube[j], k);
		}
		for (int j = 0; j < 3; j++) {
			int k;
			cin >> k;
			cube[j+3] = min(cube[j+3], k);
		}
	}
	for (int i = 0; i < 3; i++) {
		ans *= max(cube[i + 3] - cube[i],0);
	}
	cout << ans;
}
