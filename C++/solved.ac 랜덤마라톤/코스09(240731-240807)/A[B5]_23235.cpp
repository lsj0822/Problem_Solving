#include<iostream>
using namespace std;
int n, tmp, idx = 0;
int main() {
	while (1) {
		cin >> n;
		if (n == 0) return 0;
		while (n--) cin >> tmp;
		cout << "Case " << ++idx << ": Sorting... done!\n";
	}
}