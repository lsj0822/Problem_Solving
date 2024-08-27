#include<iostream>
#include<string>
using namespace std;
int n, len;
string str;
int main() {
	cin >> n;
	while (n--) {
		cin >> str;
		len = (int)str.length();
		cout << ((len >= 6 && len <= 9) ? "yes" : "no") << '\n';
	}
}