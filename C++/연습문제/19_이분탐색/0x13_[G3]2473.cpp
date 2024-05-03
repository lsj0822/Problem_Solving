#include <bits/stdc++.h>
using namespace std;
int n;
long long arr[5005], ans = 10000000000;
tuple<int, int, int> res;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(&arr[0], &arr[n]);
	for (int i = 0; i < n-2; i++) {
		int st = i+1, en = n-1;
		while (st < en) {
			long long total = arr[i] + arr[st] + arr[en];
			if (abs(total) < ans) {
				ans = abs(total);
				res = { arr[i], arr[st], arr[en] };
			}
			if (total < 0) st++;
			else en--;
		}
	}
	cout << get<0>(res) << ' ' << get<1>(res) << ' ' << get<2>(res);
}