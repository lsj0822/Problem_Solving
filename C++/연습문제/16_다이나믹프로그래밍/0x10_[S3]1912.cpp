#include <bits/stdc++.h>

using namespace std;

int n, arr[100005], res[100005], ans = -100000001;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	res[0] = arr[0];
	for (int i = 1; i < n; i++) {
		res[i] = max({ arr[i], arr[i] + res[i - 1]});
	}
	for (int i = 0; i < n; i++) {
		ans = max(ans, res[i]);
	}
	cout << ans;
}