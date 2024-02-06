#include <bits/stdc++.h>

using namespace std;
int r[13], t, n;
int main() {
	r[0] = 1; r[1] = 1; r[2] = 2;
	for (int i = 3; i <= 11; i++) {
		r[i] = r[i - 1] + r[i - 2] + r[i - 3];
	}
	cin >> t;
	while (t--) {
		cin >> n;
		cout << r[n] << '\n';
	}
}