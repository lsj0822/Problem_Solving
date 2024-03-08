#include <bits/stdc++.h>

using namespace std;
int n, divnum = 2;
int main() {
	cin >> n;
	while (n != 1) {
		if (n % divnum == 0) {
			cout << divnum << '\n';
			n /= divnum;
		}
		else divnum++;
	}
}