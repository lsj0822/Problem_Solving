#include <bits/stdc++.h>

using namespace std;

int arr[5000005];
int upperidx(int target, int len) {
	int st = 0, en = len;
	while (st < en) {
		int mid = (st + en) / 2;
		if (arr[mid] > target) en = mid;
		else st = mid + 1;
	}
	return st;
}
int loweridx(int target, int len) {
	int st = 0, en = len;
	while (st < en) {
		int mid = (st + en) / 2;
		if (arr[mid] >= target) en = mid;
		else st = mid+1;
	}
	return st;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(&arr[0], &arr[n]);
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int k;
		cin >> k;
		cout << upperidx(k, n) - loweridx(k, n) << ' ';
	}
}