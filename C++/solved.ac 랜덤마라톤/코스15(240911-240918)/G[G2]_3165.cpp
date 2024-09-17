#include<iostream>
#include<string>
#define ll long long
using namespace std;
ll n, ans = 1e18;
int k;
int fivecnt(ll num) {
	int cnt = 0;
	while (num) {
		if (num % 10 == 5) cnt++;
		num /= 10;
	}
	return cnt;
}
int main() {
	cin >> n >> k;
	n++;
	ll plusn = 1;
	while (fivecnt(n) < k) {
		if (n / plusn % 10 == 5) plusn *= 10;
		n += plusn;
	}
	cout << n;
}