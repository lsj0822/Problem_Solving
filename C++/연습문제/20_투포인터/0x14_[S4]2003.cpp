#include <bits/stdc++.h>

using namespace std;
int n, m, arr[10005], ans = 0;
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];
	int en = 0, tot = arr[0];
	for (int st = 0; st < n; st++) {
		while (en < n && tot < m) {
			en++;
			if(en != n)tot += arr[en];
		}
		if (en == n) break;
		if (tot == m) ans++;
		tot -= arr[st];
	}
	cout << ans;
}