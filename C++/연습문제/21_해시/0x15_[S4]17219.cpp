#include<iostream>
#include<map>
#include<string>
using namespace std;

int n, m;
map<string, string> IDPW;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string a, b;
		cin >> a >> b;
		IDPW[a] = b;
	}
	for (int i = 0; i < m; i++) {
		string a;
		cin >> a;
		cout << IDPW[a] << '\n';
	}
}