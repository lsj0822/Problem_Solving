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
			road.push_back({ origin[i][j], i, j }); //������ �ĺ��� Ʃ���������� �߰�
		}
	}
	sort(road.begin(), road.end()); //������ ���̰� ���� ������ ����
	//n�� �ִ������ 20�̶� n^5�� Ǯ�̵� �����ϴ�.
	for (auto v : road) {
		int c, a, b;
		tie(c, a, b) = v;
		if (dist[a][b] == c) continue; //�÷��̵� ���ȷ� �̹� �ּ�ġ�� �������ٸ�, �̴� ���η� �߰��� �ʿ䰡 ����.
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
				ans = -1; //������ ������ �÷��̵������ �ٸ��ٸ� �Ұ����� �����̱⿡ -1�� �ٲ��ش�.
				break;
			}
		}
	}
	cout << ans;
}