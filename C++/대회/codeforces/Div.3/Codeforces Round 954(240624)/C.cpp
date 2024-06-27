#include<iostream>
#include<algorithm>
#include<memory.h>
using namespace std;
int t, n ,m, oper[100005];
char c[100005];
int main() {
	cin >> t;
	while (t--) {
		memset(oper, 0, sizeof(oper));
		string str;
		cin >> n >> m >> str;
		for (int i = 0; i < m; i++) {
			int k;
			cin >> k;
			oper[k]++;
		}
		for (int i = 0; i < m; i++) cin >> c[i];
		sort(&c[0], &c[m]);
		int cidx = 0;
		for (int i = 1; i <= n; i++) {
			if (oper[i] >= 1) str[i - 1] = c[cidx++];
		}
		cout << str << '\n';
	}
}