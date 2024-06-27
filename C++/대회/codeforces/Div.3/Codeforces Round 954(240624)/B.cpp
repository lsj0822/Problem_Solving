#include<iostream>
#include<algorithm>
using namespace std;
int t, n ,m;
int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
int main() {
	cin >> t;
	while (t--) {
		int arr[105][105], vst[105][105];
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> arr[i][j];
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				bool is_greatest = true;
				int greatest = -1;
				for (int dir = 0; dir < 4; dir++) {
					int nx = i + dx[dir], ny = j + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if (arr[nx][ny] >= arr[i][j]) is_greatest = false;
					greatest = max(greatest, arr[nx][ny]);
				}
				if (is_greatest) arr[i][j] = greatest;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << arr[i][j] << ' ';
			}
			cout << '\n';
		}
	}
}