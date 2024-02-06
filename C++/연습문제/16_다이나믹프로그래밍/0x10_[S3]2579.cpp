#include <bits/stdc++.h>

using namespace std;
int n, S[505][2], C[505];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> C[i];
	}
	if (n == 1) {
		cout << C[0];
		return 0;
	}
	if (n == 2) {
		cout << C[0] + C[1];
		return 0;
	}
	S[0][0] = C[0];	S[1][0] = C[1]; S[1][1] = C[0] + C[1];
	for (int i = 2; i <= n; i++) {
		S[i][0] = max(S[i - 2][0], S[i - 2][1]) + C[i];
		S[i][1] = S[i - 1][0] + C[i];
	}
	cout << max(S[n - 1][0], S[n - 1][1]);
}