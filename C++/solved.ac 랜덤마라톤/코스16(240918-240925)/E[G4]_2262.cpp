#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, ans = 0;
vector<int> tour;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		tour.push_back(k);
	}
	while (tour.size() >= 2) {
		int rmidx = find(tour.begin(), tour.end(), tour.size()) - tour.begin(), diff = 1e5;
		if (rmidx != 0) diff = min(diff, tour[rmidx] - tour[rmidx - 1]);
		if (rmidx != tour.size()-1) diff = min(diff, tour[rmidx] - tour[rmidx + 1]);
		ans += diff;
		tour.erase(tour.begin() + rmidx);
	}
	cout << ans;
}