#include<iostream>
#include<algorithm>
using namespace std;
int n, v, arr[55], ans;
void brute_forcing(int idx, int minval, int maxval, int dep) {
	if (dep >= ans) return;
	for (int i : {2,1}) {
		if (idx + i >= n) continue;
		if (maxval - arr[idx + i] >= v || arr[idx + i] - minval >= v) {
			ans = min(ans, dep + 1);
			return;
		}
		brute_forcing(idx + i, min(minval, arr[idx + i]), max(maxval, arr[idx + i]), dep + 1);
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> v;
	ans = n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	int minval = arr[0], maxval = arr[0];
	for (int i = 1; i < n; i++) {
		minval = min(minval, arr[i]); maxval = max(maxval, arr[i]);
	}
	if (maxval - minval < v) {
		cout << n;
		return 0;
	}
	brute_forcing(0, arr[0], arr[0], 1);
	cout << ans;
}