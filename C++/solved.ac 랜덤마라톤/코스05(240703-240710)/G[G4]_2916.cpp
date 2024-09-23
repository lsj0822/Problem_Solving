#include<iostream>
using namespace std;
int n, m, __gcd = 360;
int gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}
int main() {
	cin >> n >> m;
	while(n--){
		int k;
		cin >> k;
		__gcd = gcd(__gcd, k);
	}
	while(m--){
		int k;
		cin >> k;
		cout << ((gcd(360, k)%__gcd) ? "NO" : "YES") << '\n';
	}
}