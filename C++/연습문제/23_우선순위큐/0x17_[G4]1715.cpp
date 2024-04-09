#include <iostream>
#include <queue>
using namespace std;
priority_queue<int, vector<int>, greater<int>> PQ;
int n, ans;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		PQ.push(k);
	}
	while (PQ.size() > 1) {
		int a, b;
		a = PQ.top(); PQ.pop();
		b = PQ.top(); PQ.pop();
		ans += a + b;
		PQ.push(a + b);
	}
	cout << ans;
}
