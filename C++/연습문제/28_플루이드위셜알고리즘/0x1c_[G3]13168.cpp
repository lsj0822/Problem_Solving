#include<bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
int n, m, k, r, tours[205];
double cc[205][205], not_cc[205][205], cc_cost = 0, not_cc_cost = 0;
map<string, int> city;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	fill(&cc[0][0], &cc[201][0], INF); fill(&not_cc[0][0], &not_cc[201][0], INF);
	cin >> n >> r;
	for (int i = 1; i <= n; i++) {
		string str;
		cin >> str;
		city[str] = i;
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		string str;
		cin >> str;
		tours[i] = city[str];
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		string vehicle, u, v;
		int s, e;
		double cost;
		cin >> vehicle >> u >> v >> cost;
		s = city[u]; e = city[v];
		if (vehicle == "Mugunghwa" || vehicle == "ITX-Saemaeul" || vehicle == "ITX-Cheongchun") cc[s][e] = 0;
		else if (vehicle == "S-Train" || vehicle == "V-Train") cc[s][e] = min(cc[s][e], cost / 2);
		else cc[s][e] = min(cc[s][e], cost);
		not_cc[s][e] = min(not_cc[s][e], cost);
		cc[e][s] = cc[s][e]; not_cc[e][s] = not_cc[s][e];
	}
	for (int i = 1; i <= n; i++) {
		cc[i][i] = 0; not_cc[i][i] = 0;
	}
	for (int a = 1; a <= n; a++) {
		for (int b = 1; b <= n; b++) {
			for (int c = 1; c <= n; c++) {
				cc[b][c] = min(cc[b][c], cc[b][a] + cc[a][c]);
				not_cc[b][c] = min(not_cc[b][c], not_cc[b][a] + not_cc[a][c]);
			}
		}
	}
	cc_cost = r;
	for (int i = 1; i < m; i++) {
		int cur = tours[i], pre = tours[i - 1];
		cc_cost += cc[pre][cur];
		not_cc_cost += not_cc[pre][cur];
	}
	cout << ((not_cc_cost > cc_cost) ? "Yes" : "No");
}