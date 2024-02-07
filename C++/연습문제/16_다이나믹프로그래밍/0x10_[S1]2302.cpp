#include <bits/stdc++.h>

using namespace std;

int n, k, seat[42], ans = 1, st = 0, en;
int main() {
	seat[0] = 1; seat[1] = 1;
	for (int i = 2; i <= 40; i++) {
		seat[i] = seat[i - 1] + seat[i - 2];
	}
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> en;
		ans *= seat[en - st - 1];
		st = en;
	}
	ans *= seat[n - st];
	cout << ans;
}