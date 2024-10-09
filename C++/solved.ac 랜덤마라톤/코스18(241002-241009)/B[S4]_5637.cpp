#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
const string END = "E-N-D";
string ans = "", str;

bool isletter(char c) {
	if (c >= 'a' && c <= 'z') return 1;
	if (c >= 'A' && c <= 'Z') return 1;
	if (c == '-') return 1;
	return 0;
}

int main() {
	while (1) {
		cin >> str;
		if (str == END) {
			transform(ans.begin(), ans.end(), ans.begin(), ::tolower);
			cout << ans;
			return 0;
		}
		string res = "";
		for (char c : str) {
			if (!isletter(c)) {
				if (ans.length() < res.length()) ans = res;
				res = "";
			}
			else {
				res += c;
			}
		}
		if (ans.length() < res.length()) ans = res;
	}
}