#include <bits/stdc++.h>

using namespace std;
int r[1000005], n;
int main() {
	cin >> n;
	for (int i = 2; i <= n; i++) {
		r[i] = r[i - 1] + 1;
		if (i % 2 == 0) r[i] = min(r[i], r[i / 2] + 1);
		if (i % 3 == 0) r[i] = min(r[i], r[i / 3] + 1);
	}
	cout << r[n];
}