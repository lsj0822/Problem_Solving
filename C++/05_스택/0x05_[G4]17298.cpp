#include <bits/stdc++.h>

using namespace std;

int N, num[1000001], result[1000001];
stack<int> nge;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	for (int i = N - 1; i >= 0; i--) {
		while (!nge.empty()) {
			if (num[i] < nge.top()) {
				result[i] = nge.top();
				break;
			}
			nge.pop();
		}
		if (nge.empty()) result[i] = -1;
		else result[i] = nge.top();
		nge.push(num[i]);
	}
	for (int i = 0; i < N; i++) {
		cout << result[i] << " ";
	}
}