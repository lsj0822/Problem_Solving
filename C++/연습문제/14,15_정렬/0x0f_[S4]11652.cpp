#include <bits/stdc++.h>

using namespace std;
long long arr[1000005], ans;
int n, mx = 0, cnt = 1;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(&arr[0], &arr[n]);
	ans = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] != arr[i - 1]) {
			if (cnt > mx) {
				ans = arr[i - 1];
				mx = cnt;
			}
			cnt = 1;
			continue;
		}
		cnt++;
	}
	if (cnt > mx) {
		ans = arr[n - 1];
	}
	cout << ans;
}