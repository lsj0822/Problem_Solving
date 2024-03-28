#include <bits/stdc++.h>

using namespace std;

int n, m, arr[100005], ans = 2000000001;
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(&arr[0], &arr[n]);
	int en = 0;
	for (int st = 0; st < n; st++) {
		while(en < n && arr[en] - arr[st] < m) en++;
		if (en == n) break;
		ans = min(ans, arr[en] - arr[st]);
	}
	cout << ans;
}