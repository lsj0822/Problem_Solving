#include<bits/stdc++.h>

using namespace std;

int n, k;
int board[100002];

int main() {
	fill(&board[0], &board[100002], -1);
	cin >> n >> k;
	queue<int> Q;
	board[n] = 0;
	Q.push(n);
	while (!Q.empty()) {
		int cur = Q.front(); Q.pop();
		if (cur == k) break;
		if (cur * 2 <= 100000) {
			Q.push(cur * 2);
			board[cur * 2] = board[cur];
		}
		for (int i : {cur - 1, cur + 1}) {
			if (i < 0 || i > 100000 || board[i] != -1) continue;
			Q.push(i);
			board[i] = board[cur] + 1;
		}
	}
	cout << board[k];
}