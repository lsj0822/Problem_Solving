#include <bits/stdc++.h>
using namespace std;

class abs_cmp {
public :
	bool operator()(int a, int b) {
		if (abs(a) != abs(b)) return abs(a) > abs(b);
		else return a > b;
	}
};

priority_queue<int, vector<int>, abs_cmp> PQ;
int n;

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x) PQ.push(x);
		else {
			if (PQ.empty()) {
				cout << 0 << '\n';
				continue;
			}
			cout << PQ.top() << '\n';
			PQ.pop();
		}
	}
}