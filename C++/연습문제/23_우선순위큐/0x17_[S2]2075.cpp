#include <bits/stdc++.h>

using namespace std;
priority_queue<int, vector<int>, greater<int>> PQ;
int n;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		PQ.push(k);
	}
	for (int i = n; i < n * n; i++) {
		int k;
		cin >> k;
		if (k > PQ.top()) {
			PQ.pop();
			PQ.push(k);
		}
	}
	cout << PQ.top();
}