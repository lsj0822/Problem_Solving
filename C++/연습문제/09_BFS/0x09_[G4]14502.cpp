#include <bits/stdc++.h>
using namespace std;
int n, m, arr[10][10], ans = -1, safe_num, vst[65];
int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
vector<pair<int, int>> virus, safe_zone;
int BFS(int sz) {
	int new_arr[10][10];
	queue<pair<int, int>> Q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			new_arr[i][j] = arr[i][j];
		}
	}
	for (auto c : virus) Q.push({ c.first, c.second });
	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir], ny = cur.second + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (new_arr[nx][ny] != 0) continue;
			new_arr[nx][ny] = 2;
			sz--;
			Q.push({ nx,ny });
		}
	}
	return sz;
}
void BT(int dep) {
	if (dep == 3) {
		ans = max(ans, BFS(safe_num-3));
		return;
	}
	for (int i = 0; i < safe_num; i++) {
		if (vst[i]) continue;
		vst[i] = 1;
		arr[safe_zone[i].first][safe_zone[i].second] = 1;
		BT(dep + 1);
		vst[i] = 0;
		arr[safe_zone[i].first][safe_zone[i].second] = 0;
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) virus.push_back({ i,j });
			else if (arr[i][j] == 0) safe_zone.push_back({ i,j });
		}
	}
	safe_num = safe_zone.size();
	BT(0);
	cout << ans;
}