#include<bits/stdc++.h>

using namespace std;
int n, ans = 0, level[105];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> level[i];
	}
	for (int i = n - 1; i >= 0; i--) {
		if (level[i] <= level[i - 1]) {
			ans += level[i - 1] - level[i] + 1;
			level[i - 1] = level[i] - 1;
		}
	}
	cout << ans;
}