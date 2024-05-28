#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
int n, origin[25][25], dist[25][25], ans = 0;
vector<tuple<int, int, int>> road;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	fill(&dist[0][0], &dist[21][0], INF);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> origin[i][j];
			if (i < j) continue;
			road.push_back({ origin[i][j], i, j }); //도로의 후보를 튜플형식으로 추가
		}
	}
	sort(road.begin(), road.end()); //간선의 길이가 낮은 순으로 정렬
	//n의 최대범위가 20이라 n^5의 풀이도 가능하다.
	for (auto v : road) {
		int c, a, b;
		tie(c, a, b) = v;
		if (dist[a][b] == c) continue; //플루이드 워셜로 이미 최소치가 정해졌다면, 이는 도로로 추가할 필요가 없다.
		ans += c;
		dist[a][b] = c; dist[b][a] = c;
		for (int k = 1; k <= n; k++) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] != origin[i][j]) {
				ans = -1; //원본과 구현한 플루이드워셜이 다르다면 불가능한 간선이기에 -1로 바꿔준다.
				break;
			}
		}
	}
	cout << ans;
}