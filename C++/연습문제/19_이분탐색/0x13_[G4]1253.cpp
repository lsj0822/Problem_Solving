#include <bits/stdc++.h>

using namespace std;
int n, arr[2005], ans = 0;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(&arr[0], &arr[n]);
	for (int i = 0; i < n; i++) {
		int st = 0, en = n - 1;
		while (st < en) {
			if (st == i) st++;
			else if (en == i) en--;
			else {
				int tot = arr[st] + arr[en];
				if (tot == arr[i]) {
					ans++;
					break;
				}
				else if (tot > arr[i]) en--;
				else st++;
			}
		}
	}
	cout << ans;
}