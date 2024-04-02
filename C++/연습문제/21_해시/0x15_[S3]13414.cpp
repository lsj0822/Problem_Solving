#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int k, l;
map<string, int> ls;
vector<pair<string, int>> V;
bool vector_sort(pair<string, int> a, pair <string, int> b) {
	return a.second < b.second;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> k >> l;
	for (int i = 1; i <= l; i++) {
		string str;
		cin >> str;
		ls[str] = i;
	}
	for (auto c : ls) {
		V.push_back({ c.first,c.second });
	}
	sort(V.begin(), V.end(), vector_sort);
	for (int i = 0; i < min(int(V.size()),k); i++) cout << V[i].first << '\n';
}