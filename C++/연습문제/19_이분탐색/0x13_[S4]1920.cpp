#include <bits/stdc++.h>

using namespace std;

int arr[1000005], n, m;

int binarysearch(int target) {
	int st = 0, mid, en = n-1;
	while (st <= en) {
		mid = (st + en) / 2;
		if (target > arr[mid]) {
			st = mid + 1;
		}
		else if (target < arr[mid]) {
			en = mid - 1;
		}
		else return 1;
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(&arr[0], &arr[n]);
	cin >> m;
	while (m--) {
		int k;
		cin >> k;
		cout << binarysearch(k) << '\n';
	}
}