#include <iostream>
#include <set>
#include <unordered_map>
#include <string>

using namespace std;
int n, m;
set<pair<int, int>> by_level;
set<pair<int,int>> by_algorithm[101];
unordered_map<int, pair<int,int>> problem;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int p, l, g;
		cin >> p >> l >> g;
		by_level.insert({ l,p });
		by_algorithm[g].insert({ l,p });
		problem[p] = { l,g };
	}
	cin >> m;
	while (m--) {
		string cmd;
		cin >> cmd;
		if (cmd == "recommend") {
			int g, x;
			cin >> g >> x;
			if (x == 1)cout << prev(by_algorithm[g].end())->second;
			else if (x == -1) cout << by_algorithm[g].begin()->second;
			cout << '\n';
		}
		else if (cmd == "recommend2") {
			int x;
			cin >> x;
			if (x == 1) cout << prev(by_level.end())->second;
			else if (x == -1) cout << by_level.begin()->second;
			cout << '\n';
		}
		else if (cmd == "recommend3") {
			int x, l;
			cin >> x >> l;
			set<pair<int,int>>::iterator it = by_level.lower_bound({ l,0 });
			if (x == 1) {
				if (it == by_level.end()) cout << -1;
				else cout << it->second;
			}
			else if (x == -1) {
				if (it == by_level.begin()) cout << -1;
				else cout << prev(it)->second;
			}
			cout << '\n';
		}
		else if (cmd == "add") {
			int p, l, g;
			cin >> p >> l >> g;
			by_level.insert({ l,p });
			by_algorithm[g].insert({ l,p });
			problem[p] = { l,g };
		}
		else if (cmd == "solved") {
			int p;
			cin >> p;
			pair<int,int> info = { problem[p].first, p };
			by_level.erase(by_level.find(info));
			by_algorithm[problem[p].second].erase(by_algorithm[problem[p].second].find(info));
			problem.erase(p);
		}
	}
}