#include <bits/stdc++.h>

using namespace std;
int n, arr[100005], freq[100005];
long long ans = 0;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	int en = 0;
	for (int st = 0; st < n; st++) {
		while (en < n) {
			int k = arr[en];
			if (freq[k] == 1) break;
			freq[k]++;
			en++;
		}
		ans += en - st;
		freq[arr[st]]--;
	}
	cout << ans;
}