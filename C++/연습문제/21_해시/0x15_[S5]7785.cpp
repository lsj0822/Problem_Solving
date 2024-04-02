#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

unordered_set<string> company;
vector<string> nowhere;
int n;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	while (n--) {
		string name, status;
		cin >> name >> status;
		if (status == "enter") company.insert(name);
		else company.erase(name);
	}
	for (auto m : company) nowhere.push_back(m);
	sort(nowhere.begin(), nowhere.end(), greater<string>());
	for (auto r : nowhere) cout << r << '\n';
}