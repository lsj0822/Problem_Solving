#include<iostream>
#include<string>
using namespace std;
string str;
int main() {
	while (1) {
		cin >> str;
		if (str == "0") return 0;
		for (int i = 1; i < str.length(); i++) {
			if (str[i] == '1') {
				cout << i << ' ';
				for (int j = i; j < str.length(); j += i) {
					str[j] = '1' - str[j] + '0';
				}
			}
		}
		cout << '\n';
	}
}