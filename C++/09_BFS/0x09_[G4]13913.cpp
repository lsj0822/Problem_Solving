//연결 리스트의 개념을 이용한 풀이(prv, nxt)

#include<bits/stdc++.h>

using namespace std;
int n, k;
int board[100002], vst[100002][3];
int main() {
	cin >> n >> k;
	queue<int> Q;
	fill(&vst[0][0], &vst[100002][3], -1);
	vst[n][0] = 0;
	Q.push(n);
	while (!Q.empty()) {
		int cur = Q.front(); Q.pop();
		if (cur == k) {
			vst[k][0] = vst[cur][0];
			break;
		}
		for (int i : {cur - 1, cur + 1, cur * 2}) {
			if (i < 0 || i > 100000) continue;
			if (vst[i][0] != -1) continue;
			Q.push(i);
			vst[i][0] = vst[cur][0] + 1;
			vst[i][1] = cur;
			vst[cur][2] = i;
		}
	}
	cout << vst[k][0] << '\n';
	int pr = k;
	stack<int> S;
	while (pr != n) {
		S.push(pr);
		pr = vst[pr][1];
	}
	S.push(n);
	while (!S.empty()) {
		cout << S.top() << " ";
		S.pop();
	}
}