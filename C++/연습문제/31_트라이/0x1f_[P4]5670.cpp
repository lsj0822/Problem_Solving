#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;
const int MX = 1'000'005, ROOT = 1;
int n, nxt[MX][27], unused = 2, trial;
string word_container[100005];
bool vst[MX];
int ctoi(char c) {
	return c - 'a';
}
void INSERT() {
	for (int i = 0; i < n; i++) {
		int cur = ROOT;
		for (char c : word_container[i]) {
			if (nxt[cur][ctoi(c)] == 0) {
				nxt[cur][ctoi(c)] = unused++;
				nxt[cur][26]++;
			}
			cur = nxt[cur][ctoi(c)];
		}
		vst[cur] = 1;
	}
}
int SEARCH(int i) {
	string str = word_container[i];
	int cur = nxt[ROOT][ctoi(str[0])], tmp = 1;
	for (int c = 1; c < (int)str.length(); c++) {
		if (vst[cur] || nxt[cur][26] > 1) tmp++;
		cur = nxt[cur][ctoi(str[c])];
	}
	return tmp;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	while (cin >> n) {
		fill(&nxt[0][0], &nxt[MX-1][0], 0);
		fill(&vst[0], &vst[MX-1], 0);
		trial = 0; unused = 2;
		for (int i = 0; i < n; i++) cin >> word_container[i];
		INSERT();
		for (int i = 0; i < n; i++) trial += SEARCH(i);
		cout << fixed << setprecision(2) << trial / (double)n << '\n';
	}
}