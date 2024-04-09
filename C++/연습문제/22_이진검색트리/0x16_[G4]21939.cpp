#include <iostream>
#include <string>
#include <set>
#include <unordered_map>

using namespace std;
set<pair<int,int>> problem;
unordered_map<int, int> problem_idx;

int n, m;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int p, l;
		cin >> p >> l;
		problem.insert({l,p});
		problem_idx[p] = l;
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		string cmd;
		cin >> cmd;
		if (cmd == "add") {
			int p, l;
			cin >> p >> l;
			problem.insert({ l,p });
			problem_idx[p] = l;
		}
		else if (cmd == "solved") {
			int p;
			cin >> p;
			auto it = problem.find({problem_idx[p], p});
			problem.erase(it);
			problem_idx.erase(p);
		}
		else if (cmd == "recommend") {
			int x;
			cin >> x;
			if (x == 1) cout << prev(problem.end())->second;
			else if (x == -1) cout << problem.begin()->second;
			cout << '\n';
		}
	}
}