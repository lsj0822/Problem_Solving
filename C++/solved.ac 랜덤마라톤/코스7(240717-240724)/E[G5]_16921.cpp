#include<iostream>
#include<algorithm>
using namespace std;
int n, m, r, arr[305][305], d = 0;
void array_rotation(int idx, int h, int w, int t) {
	while (t--) {
		int tmp = arr[idx][idx];
		for (int i = 1; i < w; i++) arr[idx][idx+i - 1] = arr[idx][idx+i];
		for (int i = 1; i < h; i++) arr[idx+i - 1][idx + w - 1] = arr[idx+i][idx + w - 1];
		for (int i = 1; i < w; i++) arr[idx + h - 1][idx + w - i] = arr[idx + h - 1][idx + w - 1 - i];
		for (int i = 1; i < h-1; i++) arr[idx + h - i][idx] = arr[idx + h - 1 - i][idx];
		arr[idx + 1][idx] = tmp;
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0;j < m; j++) {
			cin >> arr[i][j];
		}
	}
	while (d * 2 < min(n, m)) {
		array_rotation(d, n - d * 2, m - d * 2, r % ((n+m)*2 - 4 - d*8));
		d++;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
}