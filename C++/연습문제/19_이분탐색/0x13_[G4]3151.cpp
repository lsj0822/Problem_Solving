#include <bits/stdc++.h>

using namespace std;
int n, arr[10005];
long long ans = 0;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(&arr[0], &arr[n]);
	for (int i = 0; i < n-1; i++) {
		for (int j = i + 1; j < n; j++) {
			int tot = arr[i] + arr[j];
			ans += upper_bound(&arr[j + 1], &arr[n], -tot) - lower_bound(&arr[j + 1], &arr[n], -tot);
		}
	}
	cout << ans;
}