#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int n, m, arr[105][105], tmp[105][105], ans = 0;
int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
bool vst[105][105];
bool monopang() {
	fill(&vst[0][0], &vst[101][0], 0);
	int cnt = 0;
	queue<pair<int, int>> Q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] != 0 && vst[i][j] == 0) {
				Q.push({ i,j });
				cnt++;
				while (!Q.empty()) {
					auto cur = Q.front(); Q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.first + dx[dir], ny = cur.second + dy[dir];
						if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
						if (vst[nx][ny] || arr[nx][ny] == 0) continue;
						Q.push({ nx,ny });
						vst[nx][ny] = 1;
					}
				}
			}
		}
	}
	return (cnt == 1);
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;
			arr[i][j] = c - '0';
		}
	}
	while (1) {
		if (monopang()) {
			cout << ans;
			return 0;
		}
		fill(&tmp[0][0], &tmp[101][0], 0);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] != 0) {
					int minx = max(0, i - arr[i][j]), miny = max(0, j-arr[i][j]);
					int maxx = min(n - 1, i + arr[i][j]), maxy = min(m - 1, j + arr[i][j]);
					for (int x = minx; x <= maxx; x++) {
						for (int y = miny; y <= maxy; y++) {
							tmp[x][y] = max(tmp[x][y], arr[i][j]);
						}
					}
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				arr[i][j] = tmp[i][j];
			}
		}
		ans++;
	}
	cout << ans;
}