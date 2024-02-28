#include<iostream>
#include<string>

using namespace std;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	string nm = to_string(n) + to_string(m);
	cout << n + m - k << '\n' << stoi(nm) - k;
}