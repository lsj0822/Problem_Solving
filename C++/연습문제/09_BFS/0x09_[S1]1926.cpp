#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int brd[502][502], vst[502][502];
int n, m, large = 0, paint = 0;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int k;
			cin >> k;
			brd[i][j] = k;
		}
	}

	for (int x = 0; x < n; x++) {
		for (int y = 0; y < m; y++) {
			if (!vst[x][y] && brd[x][y]){
				int temp = 1;
				queue<pair<int, int>> Q;
				Q.push(make_pair(x,y));
				vst[x][y] = 1;
				while (!Q.empty()) {
					pair<int, int> cur = Q.front();
					Q.pop();
					for (int i = 0; i < 4; i++) {
						int nx = cur.X + dx[i];
						int ny = cur.Y + dy[i];
						if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
						if (vst[nx][ny] || brd[nx][ny] != 1) continue;
						vst[nx][ny] = 1;
						temp++;
						Q.push(make_pair(nx, ny));
					}
				}
				large = max(large, temp);
				paint++;
			}
		}
	}
	cout << paint << '\n' << large;
}