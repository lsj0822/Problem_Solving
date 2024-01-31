#include<list>
#include<iostream>

using namespace std;

int main() {
	string str;
	cin >> str;
	list<char> ls;
	for (auto s : str) {
		ls.push_back(s);
	}
	auto c = ls.end();
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		char k;
		cin >> k;
		int ord = k - 'a';
		switch (ord) {
		case 1:
			if (c != ls.begin()) { 
				c--;
				c = ls.erase(c); 
			}
			break;
		case 3:
			if (c != ls.end()) c++;
			break;
		case 11:
			if (c != ls.begin()) c--;
			break;
		case 15:
			char add;
			cin >> add;
			ls.insert(c, add);
			break;
		}
	}
	for (auto r : ls) {
		cout << r;
	}
}