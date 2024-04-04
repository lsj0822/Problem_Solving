#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<long long, long long> A;
long long n, p, q;

long long recur(long long num) {
	long long res;
	if (num == 0) return 1;
	if (A.find(num) != A.end()) return A[num];
	res = recur(num / p) + recur(num / q);
	A.insert({ num,res });
	return res;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> p >> q;
	cout << recur(n);
}
