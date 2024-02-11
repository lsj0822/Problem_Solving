#include<bits/stdc++.h>

using namespace std;
int t, n, k, arr[10005], coin[25];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		fill(&arr[0], &arr[10001], 0);
		fill(&coin[0], &coin[21], 0);
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> coin[i];
		}
		cin >> k;
		sort(&coin[0], &coin[n]);
		arr[0] = 1;
		for (int i = 0; i < n; i++) {
			for (int j = coin[i]; j <= k; j++) {
				arr[j] += arr[j - coin[i]];
			}
		}
		cout << arr[k] << '\n';
	}
}