#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
const int FULL_SEN = (1 << 26) - 1;
int words[26], n, ans = 0;
bool alpha[26];
void BT(int dep, int res) {
	if (dep > n) return;
	if (res == FULL_SEN) {
		ans += 1 << (n - dep); 
		//dep이전에 탐색을 완료했다면 나머지 원소들을 배치할 경우의 수인 2^k를 더함
		return;
	}
	BT(dep + 1, res);
	BT(dep + 1, res | words[dep]);
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		fill(&alpha[0], &alpha[26], 0);
		string str;
		cin >> str;
		for (char c : str) alpha[c - 'a'] = 1;
		int tmp = 0;
		for (int a = 0; a < 26; a++) tmp = tmp * 2 + alpha[a];
		words[i] = tmp;
	}
	BT(0, 0);
	cout << ans;
}