#include<iostream>
#include<list>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	list<int> people;
	for (int i = 1; i <= N; i++) {
		people.push_back(i);
	}
	cout << "<";
	auto c = people.begin();
	while (people.size() != 1) {
		for (int r = 0; r < M-1; r++) {
			c++;
			if (c == people.end())c = people.begin();
		}
		cout << *c << ", ";
		c = people.erase(c);
		if (c == people.end())c = people.begin();
	}
	cout << *c << ">";
}