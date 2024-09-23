#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int, int>> hl;
int n, k, ans = 1, idx = 0;
bool hatesort(pair<int, int> a, pair<int, int> b) {
	if (a.second != b.second) return a.second < b.second;
	else a.first < b.first;
}
int main() {
	cin >> n >> k;
	while (k--) {
		int a, b;
		cin >> a >> b;
		hl.push_back({ min(a,b), max(a,b)});
	}
	sort(hl.begin(), hl.end(), hatesort);
	for (int i = 0; i < hl.size(); i++) {
		if (hl[i].first < idx) continue;
		idx = hl[i].second;
		ans++;
	}
	cout << ans;
}