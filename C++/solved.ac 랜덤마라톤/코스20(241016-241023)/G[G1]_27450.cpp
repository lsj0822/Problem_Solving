#include<iostream>
using namespace std;
const int SIZE = 500'005;
int n, k;
long long power = 0, arr[SIZE], target[SIZE], sound[SIZE], prefix = 0, ans = 0;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 0; i < n; i++) cin >> target[i];
	for (int i = 0; i < n; i++) {
		if (arr[i] + power < target[i]) {
			sound[i] = (target[i] - power - arr[i] - 1) / k + 1;
			prefix += sound[i];
		}
		if (i >= k) prefix -= sound[i - k];
		power += sound[i] * k - prefix;
	}
	for (int i = 0; i < n; i++) ans += sound[i];
	cout << ans;
}