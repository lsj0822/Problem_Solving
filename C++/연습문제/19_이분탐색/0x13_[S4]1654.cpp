#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, k;
ll lan[10005];
int main() {
	cin >> k >> n;
	for (int i = 0; i < k; i++) cin >> lan[i];
	sort(&lan[0], &lan[k]);
	ll st = 0, en = (1 << 31)-1;
	while (st < en) {
		ll mid = (st + en + 1) / 2, totlan = 0;
		for (int i = 0; i < k; i++) totlan += lan[i] / mid;
		if (totlan >= n) st = mid;
		else en = mid-1;
	}
	cout << st;
}