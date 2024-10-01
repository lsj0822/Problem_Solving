#include<iostream>
#include<algorithm>
using namespace std;
const int MX = 5005;
int n, arr[MX], dp[MX];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(&arr[0], &arr[n]);
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (arr[j] % arr[i] == 0) {
				dp[j] = max(dp[j], dp[i]+1);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) ans = max(ans, dp[i]);
	cout << n - ans - 1;
}
