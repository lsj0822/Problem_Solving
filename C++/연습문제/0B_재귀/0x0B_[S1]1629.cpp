#include<bits/stdc++.h>

using namespace std;
using ll = long long;
ll A, B, C;

ll multiple(ll a, ll b, ll c) {
	if (b == 1) return a % c;
	ll var = multiple(a, b / 2, c);
	if (b % 2) return (var * var % c) * a % c;
	return (var * var) % c;
}

int main() {
	cin >> A >> B >> C;
	cout << multiple(A, B, C);
}