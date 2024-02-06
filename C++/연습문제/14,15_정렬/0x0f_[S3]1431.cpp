#include<bits/stdc++.h>

using namespace std;

string arr[55];
int n;

bool sortmethod(string a, string b) {
	if (a.size() != b.size()) return a.size() < b.size();
	int anum = 0, bnum = 0;
	for (auto ac : a) {
		if (isdigit(ac)) anum += ac - '0';
	}
	for (auto bc : b) {
		if (isdigit(bc)) bnum += bc - '0';
	}
	if (anum != bnum) return anum < bnum;
	else return a < b;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr+n, sortmethod);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << '\n';
	}
}