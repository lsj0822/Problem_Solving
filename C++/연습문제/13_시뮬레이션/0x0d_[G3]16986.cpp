#include<bits/stdc++.h>
using namespace std;
vector<int> sq[3];
int n, k, win_list[11][11];
bool result = false;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) sq[0].push_back(i);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> win_list[i][j];
		}
	}
	for (int i = 1; i < 3; i++) {
		for (int j = 0; j < 20; j++) {
			int k;
			cin >> k;
			sq[i].push_back(k);
		}
	}
	do {
		int wins[3] = { 0, }, idx[3] = { 0, };
		int l = 0, r = 1;
		while (idx[0] < n && idx[1] < 20 && idx[2] < 20) {
			int lVal = sq[l][idx[l]], rVal = sq[r][idx[r]], winner, nxt = 3 - (l+r);
			if (lVal == rVal) winner = max(l, r);
			else {
				if (win_list[lVal][rVal] == 2) winner = l;
				else winner = r;
			}
			wins[winner]++;
			if (wins[winner] == k) break;
			idx[l]++; idx[r]++;
			l = winner;	r = nxt;
		}
		if (wins[0] == k) {
			result = true;
			break;
		}
	} while (next_permutation(sq[0].begin(), sq[0].end()));
	cout << result;
}