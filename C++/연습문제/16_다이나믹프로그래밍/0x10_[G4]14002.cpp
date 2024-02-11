#include <bits/stdc++.h>

using namespace std;

int n, arr[1005], slen = 1, result[1005], ans[1005];
vector<int> vt;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	//NlogN에 LIS를 구하는 방법
	vt.push_back(arr[0]);
	result[0] = 1;
	for (int i = 1; i < n; i++) {
		if (vt.back() < arr[i]) {
			slen++;
			result[i] = slen;
			vt.push_back(arr[i]);
		}
		else {
			int pos = lower_bound(vt.begin(), vt.end(), arr[i]) - vt.begin();
			vt[pos] = arr[i];
			result[i] = pos+1;
		}
	}
	int lis = slen, idx = n-1;
	cout << slen << '\n';
	while (lis) {
		if (result[idx] == lis) {
			ans[lis] = arr[idx];
			lis--;
		}
		idx--;
	}
	for (int i = 1; i <= slen; i++) {
		cout << ans[i] << " ";
	}
}