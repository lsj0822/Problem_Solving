#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int n, m, k;
int paper[102][102], vst[102][102];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {
	cin >> n >> m >> k;
	vector<int> result;
	while (k--) {
		int px1, py1, px2, py2;
		cin >> py1 >> px1 >> py2 >> px2;
		for (int x = px1; x < px2; x++) {
			for (int y = py1; y < py2; y++) {
				paper[y][n - x - 1] = 1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!paper[j][i] && !vst[j][i]) {
				int r = 1;
				queue<pair<int, int>> Q;
				Q.push({ i,j });
				vst[j][i] = 1;
				while (!Q.empty()) {
					auto cur = Q.front(); Q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
						if (paper[ny][nx] || vst[ny][nx]) continue;
						r++;
						vst[ny][nx] = 1;
						Q.push({ nx,ny });
					}
				}
				result.push_back(r);
			}
		}
	}
	sort(result.begin(), result.end());
	cout << result.size() << '\n';
	for (auto r : result) cout << r << " ";
}