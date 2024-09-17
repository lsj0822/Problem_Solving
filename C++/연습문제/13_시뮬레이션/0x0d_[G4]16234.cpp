#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#define X first
#define Y second
using namespace std;
int n, l, r, arr[55][55], day = 0;
int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
bool open[55][55], vst[55][55];
bool open_crit(pair<int, int> p1, pair<int, int> p2) {
	int diff = abs(arr[p1.X][p1.Y] - arr[p2.X][p2.Y]);
	return (l <= diff && diff <= r);
}
void land_open() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int dir = 0; dir < 2; dir++) {
				int nx = i + dx[dir], ny = j + dy[dir];
				if (nx >= n || ny >= n) continue;
				if (open_crit({ i,j }, { nx,ny })) {
					open[nx][ny] = 1;
					open[i][j] = 1;
				}
			}
		}
	}
}
bool nomoving() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (open[i][j]) return 0;
		}
	}
	return 1;
}

void uniting() {
	vector<pair<int, int>> country;
	queue<pair<int, int>> Q;
	int people = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (open[i][j] && !vst[i][j]) {
				Q.push({ i,j });
				vst[i][j] = 1;
				while (!Q.empty()) {
					auto cur = Q.front(); Q.pop();
					people += arr[cur.X][cur.Y];
					country.push_back(cur);
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.X + dx[dir], ny = cur.Y + dy[dir];
						if (nx < 0 || nx >= n || ny < 0 || ny >= n || vst[nx][ny]) continue;
						if (!open[nx][ny]) continue;
						if (!open_crit({ cur.X,cur.Y }, { nx,ny })) continue;
						vst[nx][ny] = 1;
						Q.push({ nx,ny });
					}
				}
				for (auto c : country) {
					arr[c.X][c.Y] = people / country.size();
				}
				country.clear();
				people = 0;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	while (1) {
		fill(&open[0][0], &open[50][0], 0);
		fill(&vst[0][0], &vst[50][0], 0);
		land_open();
		if (nomoving()) break;
		uniting();
		day++;
	}
	cout << day;
}