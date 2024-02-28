#include <bits/stdc++.h>

using namespace std;

string X;
int ans[3], m_ans;
char KSA[3] = { 'K','S','A' };
int main() {
	fill(&ans[0], &ans[3], 0);
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> X;
	int xlen = X.length();
	for (auto c : X) {
		for (int i = 0; i < 3; i++) {
			if (c == KSA[(i + ans[i]) % 3]) ans[i]++;
		}
	}
	if (ans[1] == xlen) ans[1]--;
	if (ans[2] >= xlen-1) ans[2]--;
	m_ans = max({ ans[0],ans[1],ans[2] });
	cout << (X.length() - m_ans) * 2;
}