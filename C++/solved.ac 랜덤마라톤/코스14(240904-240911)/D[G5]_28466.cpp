#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, arr1[10][10], arr2[12][12], ans = 0;
vector<int> score[10][12];
int team_eval(int r[3], int c[3]) {
	int res = 0, cnt[10][12];
	for (int i = 0; i < 120; i++) cnt[i / 12][i % 12] = 0;
	for (int i = 0; i < 3; i++) {
		cnt[r[i]][c[i]]++;
		if (score[r[i]][c[i]].size() < cnt[r[i]][c[i]]) return 0;
		res += score[r[i]][c[i]][cnt[r[i]][c[i]] - 1];
	}
	return res + arr1[r[0]][r[1]] + arr1[r[0]][r[2]] + arr1[r[1]][r[2]] + arr2[c[0]][c[1]] + arr2[c[0]][c[2]] + arr2[c[1]][c[2]];
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> arr1[i][j];
		}
	}
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++) {
			cin >> arr2[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		int s; char r, c;
		cin  >> s >> r >> c;
		score[r - '0'][c - 'A'].push_back(s);
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 12; j++) {
			sort(score[i][j].begin(), score[i][j].end(), greater<>());
		}
	}
	for (int i = 0; i < 120; i++) {
		int r1 = i / 12, c1 = i % 12;
		if (score[r1][c1].size() == 0) continue;
		for (int j = 0; j < 120; j++) {
			int r2 = j / 12, c2 = j % 12;
			if (score[r2][c2].size() == 0) continue;
			for (int k = 0; k < 120; k++) {
				int r3 = k / 12, c3 = k % 12;
				if (score[r3][c3].size() == 0) continue;
				int rr[3] = { r1,r2,r3 }, cc[3] = { c1,c2,c3 };
				ans = max(ans, team_eval(rr,cc));
			}
		}
	}
	cout << ans;
}