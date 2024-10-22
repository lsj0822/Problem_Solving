#include<iostream>
using namespace std;
int n, bits = 0;
int main() {
	cin >> n;
	if (n < 0) cout << 32;
	else if (n == 0) cout << 1;
	else {
		while (n != 0) {
			n /= 2;
			bits++;
		}
		cout << bits;
	}
}