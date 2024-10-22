#include<iostream>
#include<algorithm>
using namespace std;
long long a, b;
int main() {
	while (1) {
		cin >> a >> b;
		if (a == 0 && b == 0) return 0;
		if (a < b) swap(a, b);
		int turn = 1;
		while (a%b != 0 && a <= 2*b) {
			a -= b;
			turn++;
			swap(a, b);
		}
		cout << (char)('B' - (turn % 2)) << " wins\n";
	}
}