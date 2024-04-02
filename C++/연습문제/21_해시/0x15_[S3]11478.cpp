#include<iostream>
#include<set>
#include<string>
using namespace std;
string str;
set<string> cnt;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> str;
	int slen = str.length();
	for (int i = 1; i <= slen; i++) {
		for (int j = 0; i + j <= slen; j++) {
			cnt.insert(str.substr(j, i));
		}
	}
	cout << cnt.size();
}