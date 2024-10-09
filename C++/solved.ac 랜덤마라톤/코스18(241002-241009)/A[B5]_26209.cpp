#include<iostream>
using namespace std;
int main() {
	for (int i = 0; i < 8; i++) {
		int k;
		cin >> k;
		if (k == 9) {
			cout << 'F';
			return 0;
		}
	}
	cout << 'S';
}