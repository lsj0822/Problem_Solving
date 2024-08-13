#include<iostream>
using namespace std;
long long k, a, b, ans = 0;
int main() {
	cin >> k >> a >> b;
	if (a % k != 0) {
		if (a >= 0) a = (a / k + 1) * k;
		else a = a / k * k;
	}
	if (b % k != 0) {
		if (b >= 0) b = b / k * k;
		else b = (b / k - 1) * k;
	}
	cout << (b-a)/k + 1;
}