#include<iostream>
#include<algorithm>
#include<queue>
#define X first
#define Y second
using namespace std;
int dist[205][12], c, s, t, maxdouble, ans;
queue<pair<int, int>> Q;
int main() {
	cin >> c;
	while (c--) {
		fill(&dist[0][0], &dist[201][0], -1);
		cin >> s >> t;
		dist[s][0] = 0;
		maxdouble = 0; ans = 1e8;
		Q.push({ s,0 });
		while (!Q.empty()) {
			auto cur = Q.front(); Q.pop();
			int curdist = dist[cur.X][cur.Y];
			for (int i : {0, 1}) {
				if (i) {
					if (dist[cur.X + 1][cur.Y] != -1 || (cur.X + 1) > (t + cur.Y * 3)) continue;
					dist[cur.X + 1][cur.Y] = curdist + 1;
					Q.push({ cur.X + 1, cur.Y });
				}
				else {
					if (dist[cur.X * 2][cur.Y + 1] != -1 || (cur.X * 2) > (t + (cur.Y + 1) * 3)) continue;
					dist[cur.X * 2][cur.Y + 1] = curdist + 1;
					Q.push({ cur.X * 2, cur.Y + 1 });
					maxdouble = max(maxdouble, cur.Y + 1);
				}
			}
		}
		for (int i = 0; i <= maxdouble; i++) ans = min(ans, dist[t + (i * 3)][i]);
		cout << ans << '\n';
	}
}