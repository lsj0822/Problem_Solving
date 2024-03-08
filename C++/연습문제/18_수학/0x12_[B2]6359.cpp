#include <bits/stdc++.h>

using namespace std;

int t, n;
int main() {
	cin >> t;
	//탐색이 끝난 후 문이 열려있는 경우는 약수의 개수가 홀수개인 경우, 다시 말해 제곱수이다.
	while (t--) {
		cin >> n;
		cout << int(sqrt(n)) << '\n';
	}
}