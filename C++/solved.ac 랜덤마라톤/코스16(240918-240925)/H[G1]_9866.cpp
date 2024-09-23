#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n, m, k, q, hub[205], anscnt = 0;
long long enter_dist[205][20005], leave_dist[205][20005], anscost = 0;
const long long INF = 1e15;
vector<pair<int, int>> enter_node[20005], leave_node[20005];
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> route;
void enter_dijk(int idx) {
	int pos = hub[idx];
	enter_dist[idx][pos] = 0;
	route.push({ 0,pos });
	while (!route.empty()) {
		auto cur = route.top(); route.pop();
		if (cur.first != enter_dist[idx][cur.second]) continue;
		for (auto nxt : enter_node[cur.second]) {
			long long w = cur.first + nxt.first;
			if (w >= enter_dist[idx][nxt.second]) continue;
			enter_dist[idx][nxt.second] = w;
			route.push({ w,nxt.second });
		}
	}
}

void leave_dijk(int idx) {
	int pos = hub[idx];
	leave_dist[idx][pos] = 0;
	route.push({ 0,pos });
	while (!route.empty()) {
		auto cur = route.top(); route.pop();
		if (cur.first != leave_dist[idx][cur.second]) continue;
		for (auto nxt : leave_node[cur.second]) {
			long long w = cur.first + nxt.first;
			if (w >= leave_dist[idx][nxt.second]) continue;
			leave_dist[idx][nxt.second] = w;
			route.push({ w,nxt.second });
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> k >> q;
	while (m--) {
		int u, v, d;
		cin >> u >> v >> d;
		enter_node[v].push_back({ d,u });
		leave_node[u].push_back({ d,v });
	}
	for (int i = 0; i < k; i++) cin >> hub[i];
	fill(&enter_dist[0][0], &enter_dist[201][0], INF);
	fill(&leave_dist[0][0], &leave_dist[201][0], INF);
	for (int i = 0; i < k; i++) {
		enter_dijk(i);
		leave_dijk(i);
	}
	while (q--) {
		int st, en;
		long long tmp = INF;
		cin >> st >> en;
		for (int i = 0; i < k; i++) tmp = min(tmp, enter_dist[i][st] + leave_dist[i][en]);
		if (tmp != INF) {
			anscnt++;
			anscost += tmp;
		}
	}
	cout << anscnt << '\n' << anscost;
}