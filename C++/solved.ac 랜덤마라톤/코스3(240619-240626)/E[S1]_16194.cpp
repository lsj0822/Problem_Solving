#include <bits/stdc++.h>

using namespace std;
int n, card[1005], cost[1005];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> card[i];
	}
	cost[0] = card[0];
	for (int i = 1; i < n; i++) {
		cost[i] = card[i];
		for (int j = 0; j < i; j++) {
			cost[i] = min(cost[i - j - 1] + card[j], cost[i]);
		}
	}
	cout << cost[n - 1];
}