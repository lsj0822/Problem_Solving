#include<iostream>
#include<list>

using namespace std;

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		list<char> pass;
		auto c = pass.begin();
		string order;
		cin >> order;
		for(char o : order) {
			if (o == '<') {
				if (c != pass.begin()) c--;
			}
			else if (o == '>') {
				if (c != pass.end())c++;
			}
			else if (o == '-'){
				if (c != pass.begin()) {
					c--;
					c = pass.erase(c);
				}
			}
			else {
				pass.insert(c,o);
			}
		}
		for (auto p : pass) {
			cout << p;
		}
		cout << '\n';
	}
}