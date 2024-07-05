#include <iostream>
#include <vector>
#include <string>
using namespace std;
int l;
string str;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> l >> str;
	vector<int> f(l);
	int j = 0;
	for (int i = 1; i < l; i++) {
		while (j > 0 && str[i] != str[j]) j = f[j - 1];
		if (str[i] == str[j]) f[i] = ++j;
	}
	cout << l - f[l - 1];
}