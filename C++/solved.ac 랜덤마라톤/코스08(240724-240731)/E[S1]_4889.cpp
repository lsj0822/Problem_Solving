#include<iostream>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;
string str;
int idx = 1;
int main() {
	while (1) {
		stack<char> ST;
		getline(cin, str);
		int slen = (int)str.length(), ans = slen, tmp = 0;
		if (str[0] == '-') return 0;
		for (int i = 0; i < slen; i++) {
			switch (str[i]) {
			case '{':
				ST.push('{');
				break;
			case '}':
				if (ST.size() == 0) {
					tmp++;
					ST.push('{');
				}
				else ST.pop();
			}
		}
		ans = tmp + ST.size()/2;
		cout << idx++ << ". " << ans << '\n';

	}
}