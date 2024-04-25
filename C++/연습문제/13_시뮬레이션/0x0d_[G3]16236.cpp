#include <bits/stdc++.h>
using namespace std;
int arr[25][25], n, dist[25][25], weight = 2, rtime = 0, exper = 0;
bool momhelp = false, eat = false;
int dx[4] = { -1,0,0,1 }, dy[4] = { 0,-1,1,0 };
priority_queue<tuple<int,int,int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> Q;
pair<int, int> shark;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 9) {
				shark = { i,j };
				arr[i][j] = 0;
			}
		}
	}
	while (!momhelp) {
		fill(&dist[0][0], &dist[20][20], -1);
		eat = false;
		int sx = shark.first, sy = shark.second;
		Q.push(make_tuple(0,sx,sy));
		dist[sx][sy] = 0;
		while (!Q.empty()) {
			auto cur = Q.top(); Q.pop();
			int x = get<1>(cur), y = get<2>(cur);
			int pos = arr[x][y];
			if (pos != 0 && pos < weight) {
				arr[x][y] = 0;
				shark = { x,y };
				rtime += dist[x][y];
				exper++;
				if (exper == weight) {
					weight++;
					exper = 0;
				}
				eat = true;
				while (!Q.empty()) Q.pop();
			}
			if (!eat) {
				for (int dir = 0; dir < 4; dir++) {
					int nx = x + dx[dir], ny = y + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (dist[nx][ny] != -1) continue;
					if (arr[nx][ny] > weight) continue;
					dist[nx][ny] = dist[x][y] + 1;
					Q.push(make_tuple(dist[nx][ny],nx,ny));
				}
			}
		}
		if (!eat) momhelp = 1;
	}
	cout << rtime;
}