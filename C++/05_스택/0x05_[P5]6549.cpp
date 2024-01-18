#include <bits/stdc++.h>

using namespace std;
int N;
stack<pair<long long, long long>> low;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true) {
		cin >> N;
		if (N == 0) break;
		long long result = 0, h[100005] = { 0, };
		while (!low.empty()) low.pop();
		for (int i = 1; i <= N; i++) {
			cin >> h[i];
		}

		low.push(make_pair(0, h[0]));
		for (int i = 1; i <= N + 2; i++) {
			while (!low.empty() && low.top().second > h[i]) {
				long long height = low.top().second;
				low.pop();
				long long  width = i - low.top().first - 1;
				result = max(result, height * width);
			}
			low.push(make_pair(i, h[i]));
		}
		cout << result << '\n';
	}
	
}