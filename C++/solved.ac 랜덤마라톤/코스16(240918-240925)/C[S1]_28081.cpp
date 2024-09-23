#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int w, h, n, m;
long long ans = 0, k;
vector<long long> wvec, hvec;
int main() {
	cin >> w >> h >> k;
	cin >> n;
	int prev = 0;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		hvec.push_back(tmp - prev);
		prev = tmp;
	}
	hvec.push_back(h - prev);
	cin >> m;
	prev = 0;
	for (int i = 0; i < m; i++) {
		int tmp;
		cin >> tmp;
		wvec.push_back(tmp - prev);
		prev = tmp;
	}
	wvec.push_back(w - prev);
	sort(hvec.begin(), hvec.end());
	for (int v : wvec) {
		ans += upper_bound(hvec.begin(), hvec.end(), k / v) - hvec.begin();
	}
	cout << ans;
}