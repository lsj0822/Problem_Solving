#include <bits/stdc++.h>

using namespace std;
int n, k, arr[1000005], ans = 0;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> arr[i];
	int en = 0, odd_cnt = arr[0] % 2;
	for (int st = 0; st < n; st++) {
		while (en < n - 1 && odd_cnt + arr[en + 1] % 2 <= k) {
			en++;
			odd_cnt += arr[en] % 2;
		}
		if (odd_cnt <= k) ans = max(ans, en - st + 1 - odd_cnt);
		odd_cnt -= arr[st] % 2;
	}
	cout << ans;
}