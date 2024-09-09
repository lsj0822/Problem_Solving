#include<iostream>
#include<queue>
#include<vector>
#include<tuple>
#include<algorithm>
#include<cmath>
using namespace std;
const int INF = 1e9;
int n, m, dist[20005];
vector<tuple<int,int,int>> adj[20005];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> route;
int main() {
	cin >> n >> m;
	fill(&dist[0], &dist[n+1], INF);
	while (m--) {
		int a, b, t, w;
		cin >> a >> b >> t >> w;
		adj[a].push_back({ b,t,w });
	}
	dist[1] = 0;
	route.push({ 0,1 });
	while (!route.empty()) {
		auto cur = route.top(); route.pop();
		for (auto v : adj[cur.second]) {
			int togo, nxtt, nxtw;
			tie(togo, nxtt, nxtw) = v;
			int weight = ceil(cur.first / (double)nxtw) * nxtw + nxtt;
			if (weight >= dist[togo]) continue;
			dist[togo] = weight;
			route.push({ weight, togo });
		}
	}
	cout << dist[n];
}