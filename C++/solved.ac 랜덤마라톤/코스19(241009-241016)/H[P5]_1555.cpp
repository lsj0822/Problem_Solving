#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
#include<cmath>
using namespace std;
int n;
vector<int> vec, primevec;
unordered_set<int> dp[10][10];
pair<int, int> ans = { 1e9, -1 };
bool isprime[30005];
bool prime_detection(int value) {
	if (value <= 1) return 0;
	for (int v : primevec) {
		if (value < v*v) return 1;
		if (value % v == 0) return 0;
	}
	return 1;
}
void calc(vector<int>& v) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dp[i][j].clear();
		}
	}
	for (int i = 0; i < n; i++) dp[i][i].insert(v[i]);
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n - i; j++) {
			for (int k = j; k <= j+i; k++) {
				for (int a : dp[j][k]) {
					for (int b : dp[k + 1][j + i]) {
						dp[j][i + j].insert(a + b);
						dp[j][i + j].insert(a - b);
						dp[j][i + j].insert(a * b);
						if (a > 0 && b > 0) dp[j][i + j].insert(a / b);
					}
				}
			}
		}
	}

	for (int res : dp[0][n - 1]) {
		res = abs(res);
		if (prime_detection(res)) {
			ans.first = min(ans.first, res);
			ans.second = max(ans.second, res);
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		vec.push_back(k);
	}
	sort(vec.begin(), vec.end());
	fill(&isprime[0], &isprime[30000], 1);
	for (int i = 2; i <= 27000; i++) {
		if (!isprime[i]) continue;
		for (int j = 2; i * j <= 27000; i++) {
			isprime[i * j] = 0;
		}
	}
	for (int i = 2; i <= 27000; i++) {
		if (isprime[i]) primevec.push_back(i);
	}
	do {
		calc(vec);
	} while (next_permutation(vec.begin(), vec.end()));
	if (ans.first == 1e9 && ans.second == -1) cout << -1;
	else cout << ans.first << '\n' << ans.second;
}