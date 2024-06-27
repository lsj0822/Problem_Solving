#include<iostream>
#include<queue>
#define X first
#define Y second

using namespace std;
queue<int> Q;
int n, num[200005];
long long ans = 0;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	for (int i = 1; i < n; i++) {
		if (num[i] < num[i - 1]) {
			Q.push(i - 1);
		}
	}
	Q.push(n - 1);
	for (int i = 0; i < n; i++) {
		ans += (Q.front() + 1 - i);
		if (Q.front() == i) Q.pop();
	}
	cout << ans;
}