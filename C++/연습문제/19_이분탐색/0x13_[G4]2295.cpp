#include <bits/stdc++.h>

using namespace std;

vector<int> vec;
int n, arr[1005];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(&arr[0], &arr[n]);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			vec.push_back(arr[i] + arr[j]);
		}
	}
	sort(vec.begin(), vec.end());
	for (int i = n - 1; i > 0; i--) {
		for (int j = 0; j < n; j++) {
			if (binary_search(vec.begin(), vec.end(), arr[i] - arr[j])) {
				cout << arr[i];
				return 0;
			}
		}
	}
}