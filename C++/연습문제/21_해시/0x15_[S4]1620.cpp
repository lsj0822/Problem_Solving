#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;
unordered_map<string, int> pokemon;
string poke_idx[100005];
int n, m;

int main() {
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string po;
		cin >> po;
		pokemon[po] = i;
		poke_idx[i] = po;
	}
	while (m--) {
		string str;
		cin >> str;
		if (isdigit(str[0])) cout << poke_idx[stoi(str)] << '\n';
		else cout << pokemon[str] << '\n';
	}
}