#include <bits/stdc++.h>

using namespace std;

int N;
queue<int> Q;

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		Q.push(i);
	}

	while (Q.size() != 1) {
		Q.pop();
		int t;
		t = Q.front();
		Q.pop();
		Q.push(t);
	}
	cout << Q.front();
}