#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int arr[105], n, ans[2] = { 0,0 };
bool m1[105];
vector<int> nullday;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] == -1) {
			nullday.push_back(i);
			m1[i] = 1;
		}
	}
	reverse(nullday.begin(), nullday.end());
	for (int v : nullday) {
		if (v == 0) arr[0] = 0;
		else if (v == n - 1) continue;
		else {
			if (arr[v + 1] > 0) arr[v] = arr[v + 1] - 1;
		}
	}
	int day = -1;
	for (int i = 0; i < n; i++) {
		if (arr[i] > 0 && day + 1 != arr[i]) {
			cout << -1;
			return 0;
		}
		if (arr[i] == 0) ans[0]++;
		if (arr[i] == -1) ans[1]++;
		day = arr[i];
	}
	cout << ans[0] << ' ' << ans[0]+ans[1];
}