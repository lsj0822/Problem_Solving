#include <bits/stdc++.h>

using namespace std;

int n, m, snack[1000005];
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> m >> n;
	for (int i = 0; i < n; i++) cin >> snack[i];
	int st = 0, en = 1000000000;
	while (st < en) {
		int mid = (st + en + 1) / 2, totsnack = 0;
		for (int i = 0; i < n; i++) totsnack += snack[i] / mid;
		if (totsnack >= m) st = mid;
		else en = mid - 1;
	}
	cout << st;
}