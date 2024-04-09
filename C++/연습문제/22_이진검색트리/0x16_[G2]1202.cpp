#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int n, k;
long long ans = 0;
pair<int, int> jewel[300005];
multiset<int> bag;

bool jewel_sort(pair<int, int> a, pair<int, int> b) {
	return a.second > b.second;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> jewel[i].first >> jewel[i].second;
	sort(&jewel[0], &jewel[n], jewel_sort);
	for (int i = 0; i < k; i++) {
		int b;
		cin >> b;
		bag.insert(b);
	}
	for (int i = 0; i < n; i++) {
		auto it = bag.lower_bound(jewel[i].first);
		if (it == bag.end()) continue;
		ans += jewel[i].second;
		bag.erase(it);
	}
	cout << ans;
}