#include<iostream>
#include<string>
#include<vector>
using namespace std;
int t;
vector<string> ls;
vector<pair<char, string>> rule;
void changing_word(char crit, string change) {
	for (int i = 0; i < ls.size(); i++) {
		for (int j = 0; j < ls[i].size(); j++) {
			if (ls[i][j] == crit) {
				ls[i].replace(j, 1, change);
				break;
			}
		}
	}
}
int main() {
	cin >> t;
	cin.ignore();
	while (t--) {
		string rules, origin;
		ls.clear(); rule.clear();
		getline(cin, rules); getline(cin, origin);
		for (int i = 0; i < rules.size(); i += 5) {
			rule.push_back({ rules[i], rules.substr(i + 2,2) });
		}
		string str = "";
		for (int i = 0; i < origin.size(); i++) {
			if (origin[i] == ' ') {
				ls.push_back(str);
				str = "";
			}
			else str += origin[i];
		}
		ls.push_back(str);
		for (auto cur : rule) changing_word(cur.first, cur.second);
		cout << "Transformed strings: ";
		for (string str : ls) cout << str << ' ';
		cout << '\n';
	}
}