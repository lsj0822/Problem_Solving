#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;
int n, k;
const int MX = 1'000'005;
string arr[2];
long long d[2][2][100005];
queue<pair<int, int>> Q[2];
int main() {
	cin >> n >> k;
	fill(&d[0][0][0], &d[1][1][100002], MX);
	for (int i = 0; i < 2; i++) cin >> arr[i];
	for (int i = 0; i < 2; i++) {
		if (arr[i][0] == '.') {
			d[i][i][0] = 0;
			Q[i].push({i,0});
		}
	}
	for (int i = 0; i < 2; i++) {
		while (!Q[i].empty()) {
			auto cur = Q[i].front(); Q[i].pop();
			for (int dir = 0; dir < 2; dir++) {
				int nx, ny;
				if (dir == 0) nx = 1 - cur.first, ny = cur.second;
				else nx = cur.first, ny = cur.second + 1;
				if (ny >= n || arr[nx][ny] == '#' || d[i][nx][ny] != MX) continue;
				d[i][nx][ny] = d[i][cur.first][cur.second] + 1;
				Q[i].push({nx,ny});
			}
		}
	}
	if (d[0][0][n - 1] == MX && d[0][1][n - 1] == MX
		&& d[1][0][n - 1] == MX && d[1][1][n - 1] == MX) {
		cout << -1;
		return 0;
	}
	if (k == 1) {
		long long ans = MX;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				ans = min(ans, d[i][j][n - 1]);
			}
		}
		cout << ans;
		return 0;
	}
	string p = "" + arr[0].substr(0,1) + arr[0].substr(n-1) + arr[1].substr(0,1) + arr[1].substr(n-1);
	if (p == "#..#" || p == ".##.") {
		cout << -1;
	}
	else if(p == "##.." || p == "..##") {
		if (p == "##..") cout << (d[1][1][n-1]+1)*k - 1;
		else cout << (d[0][0][n-1]+1)*k - 1;
	}
	else if (p == "#..." || p == "..#.") {
		if (p == "#...") cout << (d[1][1][n-1]+1)*(k-1) + min(d[1][0][n-1],d[1][1][n-1]);
		else cout << (d[0][0][n-1]+1)*(k-1) + min(d[0][0][n-1], d[0][1][n-1]);
	}
	else if (p == ".#.." || p == "...#") {
		if (p == ".#..") cout << min(d[0][1][n-1], d[1][1][n-1]) + (d[1][1][n-1]+1)*(k-1);
		else cout << min(d[0][0][n-1], d[1][0][n-1]) + (d[0][0][n-1]+1)*(k-1);
	}
	else if (p == "....") {
		long long ans = MX * (long long)k;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				if (i == j) ans = min(ans, (d[i][i][n - 1] + 1) * k - 1);
				else {
					long long tmp = d[i][j][n - 1] + (d[j][j][n - 1] + 1) * (k - 1);
					ans = min(ans, tmp);
				}
			}
		}
		cout << ans;
	}
}