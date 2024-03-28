#include <bits/stdc++.h>

using namespace std;

bool nonprime[4000005];
vector<int> prime;
int ans = 0, n;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 2; i <= 4000000; i++) {
		if (nonprime[i] == 1) continue;
		for (int j = 2; i * j <= 4000000; j++) nonprime[i * j] = 1;
	}
	for (int i = 2; i <= 4000000; i++) if (nonprime[i] == 0) prime.push_back(i);
	int en = 0, s = prime.size(), tot = prime[0];
	for (int st = 0; st < s; st++) {
		while (en < s && tot < n) {
			en++;
			if(en != s) tot += prime[en];
		}
		if (en == s) break;
		if (tot == n) ans++;
		tot -= prime[st];
	}
	cout << ans;
}