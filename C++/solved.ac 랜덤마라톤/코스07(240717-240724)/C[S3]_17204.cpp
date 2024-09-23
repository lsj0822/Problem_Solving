#include<iostream>
using namespace std;
int arr[155], n, k, target = 0, ans = 0;
int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> arr[i];
	while (ans <= n) {
		if (target == k) {
			cout << ans;
			return 0;
		}
		target = arr[target];
		ans++;
	}
	cout << -1;
	return 0;
}