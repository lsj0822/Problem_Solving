#include<iostream>
using namespace std;
int t, d, pancake[1005], maxpan, ans;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	for(int test = 1; test <= t; test++) {
		cin >> d;
		maxpan = 0;
		for (int i = 0; i < d; i++) {
			cin >> pancake[i];
			maxpan = max(maxpan, pancake[i]);
		}
		ans = maxpan;
		for (int i = 2; i <= maxpan; i++) {
			int tmp = 0;
			for (int p = 0; p < d; p++) {
				tmp += (pancake[p] - 1) / i;
			}
			ans = min(ans, tmp + i);
		}
		cout << "Case #" << test << ": " << ans << '\n';
	}
}