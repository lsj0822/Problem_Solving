#include <bits/stdc++.h>

using namespace std;

int arr[1000005];
vector<int> tmp, uni;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		tmp.push_back(arr[i]);
	}
	sort(tmp.begin(), tmp.end());
	for (int i = 0; i < tmp.size(); i++) {
		if (i == 0 || tmp[i] != tmp[i - 1]) uni.push_back(tmp[i]);
	}
	for (int i = 0; i < n; i++) {
		cout << lower_bound(uni.begin(), uni.end(), arr[i]) - uni.begin() << ' ';
	}
}