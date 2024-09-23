#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;
int nlen;
string n;
unordered_set<string> ls;
void BT(int dep, int st, int en, string str) {
	if (dep == nlen) {
		ls.insert(str);
		return;
	}
	if (st-1 >= 0) BT(dep + 1, st - 1, en, str + n.substr(st-1, dep+1));
	if (en + 1 < nlen) BT(dep + 1, st, en + 1, str + n.substr(st, dep+1));
}
int main() {
	cin >> n;
	nlen = n.length();
	for (int i = 0; i < nlen; i++) {
		string tmp = "";
		BT(1, i, i, tmp + n[i]);
	}
	cout << ls.size();
}