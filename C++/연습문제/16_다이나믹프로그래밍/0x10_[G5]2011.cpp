#include <bits/stdc++.h>

using namespace std;

string str;
int ans[5005], n, MOD = 1000000;

bool xmeta(int a, int b) {
	int x = (str[a] - '0') * 10 + str[b] - '0';
	return (x >= 10 && x <= 26);
}

int main() {
	cin >> str;
	n = str.length();
	if (str[0] == '0' || (str[0] >= '3' && str[1] == '0')) {
		cout << 0;
		return 0;
	}
	ans[0] = 1;
	if (xmeta(0, 1) && str[1] != '0') ans[1] = 2;
	else ans[1] = 1;
	for (int i = 2; i < n; i++) {
		if (str[i] == '0' && str[i - 1] >= '3') {
			cout << 0;
			return 0;
		}
		if (str[i] != '0') ans[i] = ans[i - 1];
		if (xmeta(i-1,i)) {
			ans[i] = (ans[i] + ans[i - 2]) % MOD;
		}
	}
	cout << ans[n - 1];
}