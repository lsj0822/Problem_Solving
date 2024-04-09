#include<iostream>
#include <queue>
using namespace std;
priority_queue<long long, vector<long long>, greater<long long>> PQ;
int t, n;
long long ans;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	while (t--) {
		ans = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int k; cin >> k;
			PQ.push(k);
		}
		for (int i = 0; i < n - 1; i++) {
			long long a, b;
			a = PQ.top(); PQ.pop();
			b = PQ.top(); PQ.pop();
			ans += a + b;
			PQ.push(a + b);
		}
		cout << ans << '\n';
		PQ.pop();
	}
}