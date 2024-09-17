#include<iostream>
#include<string>
#include<vector>
#include<string>
using namespace std;
int t;
char oper[10], operls[3] = {' ', '+','-'};
vector<string> ans;
string eq(int len) {
	string tmp = "1";
	for (int i = 0; i < len; i++) {
		tmp += oper[i] + to_string(i + 2);
	}
	return tmp;
}
int calc(int len) {
	int res = 0, bf = 1, tmp = 1;
	for (int i = 0; i < len; i++) {
		if (oper[i] == ' ') tmp = tmp * 10 + i + 2;
		else {
			res = res + bf * tmp;
			tmp = i + 2;
			bf = (oper[i] == '+' ? 1 : -1);
		}
	}
	return res + bf * tmp;
}
void BT(int dep, int target) {
	if (dep == target-1) {
		if (calc(dep) == 0) ans.push_back(eq(dep));
	}
	else {
		for (int i : {0, 1, 2}) {
			oper[dep] = operls[i];
			BT(dep + 1, target);
		}
	}
}
int main() {
	cin >> t;
	while (t--) {
		int k;
		cin >> k;
		ans.clear();
		BT(0, k);
		for (string res : ans) cout << res << '\n';
		cout << '\n';
	}
}
