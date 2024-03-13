#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n, tree[1000005];
ll m;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> tree[i];
	int st = 0, en = 1000000000;
	while (st < en) {
		int mid = (st + en + 1) / 2;
		ll tottree = 0;
		for (int i = 0; i < n; i++) if (tree[i] - mid > 0) tottree += tree[i] - mid;
		if (tottree >= m) st = mid;
		else en = mid - 1;
	}
	cout << st;
}