#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#define ll long long
#define X first
#define Y second
using namespace std;
const ll INF = 1e15;
vector<pair<ll, int>> node[100005];
priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> route;
int n, m;
ll odd_dist[100005], even_dist[100005];
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	fill(&odd_dist[0], &odd_dist[n + 1], INF);
	fill(&even_dist[0], &even_dist[n + 1], INF);
	while (m--) {
		int u, v; ll w;
		cin >> u >> v >> w;
		node[u].push_back({ w,v });
		node[v].push_back({ w,u });
	}
	even_dist[1] = 0;
	route.push({ 0,1 });
	while (!route.empty()) {
		auto cur = route.top(); route.pop();
		if ((cur.X % 2  == 1 && cur.X != odd_dist[cur.Y])||
			(cur.X % 2 == 0 && cur.X != even_dist[cur.Y]))continue;
		for (auto nxt : node[cur.Y]) {
			ll weight = cur.X + nxt.X;
			if (weight % 2 == 0) {
				if (weight >= even_dist[nxt.Y]) continue;
				even_dist[nxt.Y] = weight;
			}
			else {
				if (weight >= odd_dist[nxt.Y])continue;
				odd_dist[nxt.Y] = weight;
			}
			route.push({ weight, nxt.Y });
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << (odd_dist[i] == INF ? -1 : odd_dist[i]) << ' ' << (even_dist[i] == INF ? -1 : even_dist[i]) << '\n';
	}
}