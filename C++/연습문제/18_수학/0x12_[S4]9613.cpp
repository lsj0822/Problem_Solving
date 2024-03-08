#include <bits/stdc++.h>

using namespace std;
int t;
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

int main() {
	cin >> t;
	while (t--) {
		int n, arr[105];
		long long ans = 0;
		cin >> n;
		for (int i = 0; i < n; i++) cin >> arr[i];
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				ans += gcd(arr[i], arr[j]);
			}
		}
		cout << ans << '\n';
	}
}