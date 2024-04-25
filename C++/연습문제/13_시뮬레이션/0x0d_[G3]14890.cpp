#include <bits/stdc++.h>
using namespace std;
int arr[105][105], vst[105], ans = 0, n , l;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	//vertical detection
	for (int i = 0; i < n; i++) {
		int height = arr[i][0];
		bool result = true;
		memset(vst, 0, sizeof(vst));
		for (int j = 1; j < n; j++) {
			if (height == arr[i][j]) continue;
			else if (abs(height - arr[i][j]) == 1) {
				switch (height - arr[i][j]) {
				case 1:
					for (int a = 1; a < l; a++) {
						if (arr[i][j] != arr[i][j + a] || vst[j+a] == 1 || j+a >= n) {
							result = false;
							break;
						}
					}
					if (result) {
						for (int a = 0; a < l; a++) {
							vst[j + a] = 1;
						}
						height--;
					}
					break;
				case -1:
					for (int a = 0; a < l; a++) {
						if (arr[i][j-1] != arr[i][j - a-1] || vst[j - a-1] == 1 || j - a-1 < 0) {
							result = false;
							break;
						}
					}
					if (result) {
						for (int a = 0; a < l; a++) {
							vst[j - a-1] = 1;
						}
						height++;
					}
					break;
				}
			}
			else {
				result = false;
				break;
			}
		}
		if (result) ans++;
	}

	//horizontal
	for (int i = 0; i < n; i++) {
		int height = arr[0][i];
		bool result = true;
		memset(vst, 0, sizeof(vst));
		for (int j = 1; j < n; j++) {
			if (height == arr[j][i]) continue;
			else if (abs(height - arr[j][i]) == 1) {
				switch (height - arr[j][i]) {
				case 1:
					for (int a = 1; a < l; a++) {
						if (arr[j][i] != arr[j+a][i] || vst[j + a] == 1 || j + a >= n) {
							result = false;
							break;
						}
					}
					if (result) {
						for (int a = 0; a < l; a++) {
							vst[j + a] = 1;
						}
						height--;
					}
					break;
				case -1:
					for (int a = 0; a < l; a++) {
						if (arr[j-1][i] != arr[j-a-1][i] || vst[j - a-1] == 1 || j - a-1 < 0) {
							result = false;
							break;
						}
					}
					if (result) {
						for (int a = 0; a < l; a++) {
							vst[j - a-1] = 1;
						}
						height++;
					}
					break;
				}
			}
			else {
				result = false;
				break;
			}
		}
		if (result) ans++;
	}
	cout << ans;
}