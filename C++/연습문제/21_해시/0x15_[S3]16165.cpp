#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
map<string, vector<string>> girl;
map<string, string> aff;
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string name;
		int mem;
		cin >> name >> mem;
		for (int j = 0; j < mem; j++) {
			string memname;
			cin >> memname;
			girl[name].push_back(memname);
			aff[memname] = name;
		}
	}
	for (int i = 0; i < m; i++) {
		string who; bool qtype;
		cin >> who >> qtype;
		if (qtype) {
			cout << aff.find(who)->second << '\n';
		}
		else {
			sort(girl[who].begin(), girl[who].end());
			for (auto c : girl[who]) {
				cout << c << '\n';
			}
		}
	}
}