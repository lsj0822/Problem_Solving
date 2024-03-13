#include <bits/stdc++.h>

using namespace std;

int n, arr[100005], minVal = 2000000009;
pair<int, int> ans;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 0; i < n-1; i++) {
		int idx = lower_bound(&arr[i+1], &arr[n], -arr[i]) - &arr[0];
		for (int k = idx - 1; k <= idx + 1; k++) {
			if (k == i || k >= n) continue;
			if (abs(arr[i] + arr[k]) < minVal) {
				minVal = abs(arr[i] + arr[k]);
				ans = { arr[i], arr[k] };
			}
		}
	}
	cout << ans.first << ' ' << ans.second;
}