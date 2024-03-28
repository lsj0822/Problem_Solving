#include <bits/stdc++.h>

using namespace std;
int n, k, arr[200005], freq[100005], ans = 0;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> arr[i];
	int en = 0;
	freq[arr[en]]++;
	for (int st = 0; st < n; st++) {
		while (en < n && freq[arr[en]]<=k) {
			en++;
			if(en != n) freq[arr[en]]++;
		}
		ans = max(ans, en - st);
		freq[arr[st]]--;
	}
	cout << ans;
}