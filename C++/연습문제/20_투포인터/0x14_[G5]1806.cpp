#include <bits/stdc++.h>

using namespace std;

int n, s, arr[100005], ans = 100005;
int main() {
	cin >> n >> s;
	for (int i = 0; i < n; i++) cin >> arr[i];
	int en = 0, tmp = arr[0];
	for (int st = 0; st < n; st++) {
		while (en < n && tmp < s) {
			en++;
			if (en != n) tmp += arr[en];
		}
		if (en == n) break;
		ans = min(ans, en - st + 1);
		tmp -= arr[st];
	}
	if (ans == 100005) ans = 0;
	cout << ans;
}