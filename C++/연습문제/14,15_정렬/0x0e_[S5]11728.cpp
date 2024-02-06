#include<iostream>
#include<queue>
using namespace std;


int n, m, idx1 = 0, idx2 = 0;
queue<int> L1, L2;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		L1.push(k);
	}
	for (int i = 0; i < m; i++) {
		int k;
		cin >> k;
		L2.push(k);
	}
	while (!L1.empty() && !L2.empty()) {
		if (L1.front() > L2.front()) {
			cout << L2.front();
			L2.pop();
		}
		else {
			cout << L1.front();
			L1.pop();
		}
		cout << " ";
	}
	if (L1.empty()) {
		while (!L2.empty()) {
			cout << L2.front() << " ";
			L2.pop();
		}
	}
	else {
		while (!L1.empty()) {
			cout << L1.front() << " ";
			L1.pop();
		}
	}
}