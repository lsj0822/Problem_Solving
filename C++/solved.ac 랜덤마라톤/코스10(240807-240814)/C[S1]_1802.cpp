#include<iostream>
#include<string>
using namespace std;
int n;
string paper;
bool ispaper(string p){
	int plen = (int)p.length();
	if (plen == 1) return 1;
	for (int i = 0; i <plen / 2; i++) {
		if (p[i] == p[plen - 1 - i]) return 0;
	}
	return ispaper(p.substr(0,plen/2)) && ispaper(p.substr(plen / 2 + 1, plen / 2));
}
int main() {
	cin >> n;
	while (n--) {
		cin >> paper;
		cout << (ispaper(paper) ? "YES" : "NO") << '\n';
	}
}