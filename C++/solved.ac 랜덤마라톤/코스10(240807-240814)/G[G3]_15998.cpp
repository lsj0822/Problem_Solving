#include<iostream>
#include<vector>
#define ll long long
#define X first
#define Y second
using namespace std;
int n;
ll money = 0, charge, cu;
pair<ll, ll> ls[300005];
vector<ll> vec;
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	else return gcd(b, a%b);
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> ls[i].X >> ls[i].Y;
	}
	for (int i = 0; i < n; i++) {
		if (ls[i].X > 0) {
			if (money + ls[i].X != ls[i].Y) {
				cout << -1;
				return 0;
			}
		}
		else{
			charge = ls[i].Y - ls[i].X - money;
			if (money + ls[i].X >= 0) {
				if (money + ls[i].X != ls[i].Y || charge) {
					cout << -1;
					return 0;
				}
			}
			else {
				if (charge <= 0) {
					cout << -1;
					return 0;
				}
				vec.push_back(charge);
			}
		}
		money = ls[i].Y;
	}
	if (vec.size() == 0) cu = 1;
	else {
		cu = vec[0];
		for (int i = 1; i < vec.size(); i++) cu = gcd(cu, vec[i]);
	}
	money = 0;
	for (int i = 0; i < n; i++) {
		charge = ls[i].Y - ls[i].X - money;
		if (ls[i].X < 0 && ls[i].Y >= cu && charge) {
			cout << -1;
			return 0;
		}
		money = ls[i].Y;
	}
	cout << cu;
}