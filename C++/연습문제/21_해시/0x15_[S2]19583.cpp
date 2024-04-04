#include <iostream>
#include <set>
#include <string>

using namespace std;
string stime[3];
int ss, ee, qq, ans = 0;
set<string> bf, at;

int ttoi(string t) {
	return stoi(t.substr(0, 2)) * 60 + stoi(t.substr(3, 2));
}
int main() {
	for (int i = 0; i < 3; i++) cin >> stime[i];
	ss = ttoi(stime[0]);
	ee = ttoi(stime[1]);
	qq = ttoi(stime[2]);
	while (1) {
		string t, n;
		cin >> t >> n;
		if (cin.eof()) break;
		int ct = ttoi(t);
		if (ct <= ss) bf.insert(n);
		else if (ct >= ee && ct <= qq) at.insert(n);
	}
	for (auto a : at) {
		if (bf.find(a) != bf.end()) ans++;
	}
	cout << ans;
}