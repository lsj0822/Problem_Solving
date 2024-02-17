#include<bits/stdc++.h>

using namespace std;
int n, k, arr[10005], coin[105], idx = 1;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	fill(&arr[0], &arr[10001], 10001);
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
		if(coin[i] <= k) arr[coin[i]] = 1;
	}
	sort(&coin[0], &coin[n]);
	arr[0] = 0;
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j < n; j++) {
			if (i - coin[j] <= 0) break;
			arr[i] = min(arr[i - coin[j]]+1,arr[i]);
		}
	}
	if (arr[k] != 10001)cout << arr[k];
	else cout << -1;
}