#include<bits/stdc++.h>
using namespace std;
int n;
int main() {
	n = 100;
	cout << n << '\n';
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			int val;
			if (i == j) val = 0;
			else if (i == n || j == n) val = 1;
			else val = 10000;
			cout << val << ' ';
		}
		cout << '\n';
	}
}