#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define X first
#define Y second

using namespace std;

int n, m, ans = 1000005;
int board[55][55], cd[55][55], cl[15], vst[15];
vector<pair<int, int>> chicken;
vector<pair<int, int>> house;

void find_total() {
	int res = 0;
	for(auto i : house){
		int dist = 150;
		for (int j = 0; j < m; j++) {
			auto cur = chicken[cl[j]];
			dist = min(dist,abs(i.X - cur.X) + abs(i.Y - cur.Y));
		}
		res += dist;
	}

	ans = min(ans, res);
}
void bt(int dep, int srt) {
	if (dep == m) {
		find_total();
		return;
	}
	for (int i = srt; i < chicken.size(); i++) {
			if(!vst[i]){
				cl[dep] = i;
				vst[i] = 1;
				bt(dep + 1, i);
				vst[i] = 0;
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 2) {
				chicken.push_back({i,j});
			}
			if (board[i][j] == 1) {
				house.push_back({ i,j });
			}
		}
	}
	bt(0, 0);
	cout << ans;
}