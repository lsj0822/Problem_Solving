#include<iostream>
#include<cmath>
#include<queue>
#include<algorithm>
#define X first
#define Y second
#define ll long long
using namespace std;
int n, w;
double m;
pair<ll,ll> pos[1005];
const double MX = 1e18;
double dist[1005][1005], ans[1005];

priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> route;

double cal_dist(pair<ll, ll> a, pair<ll, ll> b) {
	double distsum = (a.X - b.X) * (a.X - b.X) + (a.Y - b.Y) * (a.Y - b.Y);
	double res = sqrt(distsum);
	return (res<=m?res:MX);
}

int main() {
	cin >> n >> w >> m;
	fill(&ans[0], &ans[n + 1], MX);
	for (int i = 1; i <= n; i++) cin >> pos[i].X >> pos[i].Y;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dist[i][j] = cal_dist(pos[i], pos[j]);
		}
	}

	for (int i = 0; i < w; i++) {
		int a, b;
		cin >> a >> b;
		dist[a][b] = 0; dist[b][a] = 0;
	}

	ans[1] = 0;
	route.push({ 0,1 });
	while (!route.empty()) {
		auto cur = route.top(); route.pop();
		if (cur.first > ans[cur.second]) continue;
		for (int i = 1; i <= n; i++) {
			if (dist[cur.second][i] == MX) continue;
			double w = cur.first + dist[cur.second][i];
			if (ans[i] <= w) continue;
			ans[i] = w;
			route.push({ w,i });
		}
	}
	cout << (ll)floor(ans[n]*1000);
}