#include<iostream>
#include<algorithm>
using namespace std;
int n, m, arr[200005], minn[200005], maxn[200005], ans = -1e9;
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	minn[0] = arr[1]; maxn[n] = arr[n];
	for (int i = 1; i <= m; i++) minn[i] = min(minn[i - 1], arr[i+1]);
	for (int i = 1; i <= m; i++) maxn[n-i] = max(maxn[n-i+1], arr[n - i]);
	for (int i = 0; i <= m; i++) ans = max({ ans, maxn[n-m+i] - arr[i + 1], arr[n - i] - minn[m-i] });
	cout << ans;
}