#include<bits/stdc++.h>
using namespace std;

int F, S, G, U, D;
int sl[1000002];
int main() {
	cin >> F >> S >> G >> U >> D;
	fill(sl, sl + 1000001, -1);
	queue<int> Q;
	sl[S] = 0;
	Q.push(S);
	while (!Q.empty()) {
		int cur = Q.front(); Q.pop();
		if (cur == G) {
			cout << sl[cur];
			return 0;
		}
		for (int k : {cur + U, cur - D}) {
			if (k > F || k <= 0) continue;
			if (sl[k] >= 0) continue;
			sl[k] = sl[cur] + 1;
			Q.push(k);
		}
	}
	cout << "use the stairs";
}