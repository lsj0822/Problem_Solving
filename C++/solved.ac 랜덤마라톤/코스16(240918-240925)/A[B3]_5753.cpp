#include<iostream>
#include<algorithm>
using namespace std;
int n, d, arr[105];
bool isattend(int n) {
	for (int i = 0; i < n; i++) {
		if (arr[i]==d) return 1;
	}
	return 0;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	while (1) {
		cin >> n >> d;
		if (n == 0 && d == 0) return 0;
		fill(&arr[0], &arr[n + 1], 0);
		for (int i = 0; i < d; i++) {
			for (int j = 0; j < n; j++) {
				int k;
				cin >> k;
				arr[j] += k;
			}
		}
		cout << (isattend(n) ? "yes" : "no") << '\n';	
	}
}