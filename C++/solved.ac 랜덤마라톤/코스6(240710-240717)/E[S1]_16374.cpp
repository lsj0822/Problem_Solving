#include<iostream>
#include<algorithm>
#include<vector>
#include<fstream>
using namespace std;
vector<int> ls;
int t, ans[10];
pair<int, int> node[9];
int gcd(int a, int b){
	if (b == 0) return a;
	else return gcd(b, a % b);
}

void BT() {
	int res = 1e8;
	do {
		int tmp = 0;
		for (int i = 0; i < 9; i++) {
			if (tmp > res) break;
			if (gcd(ls[node[i].first - 1], ls[node[i].second - 1]) != 1) tmp++;
		}
		if (tmp < res) {
			res = tmp;
			for (int i = 0; i < 10; i++) ans[i] = ls[i];
		}
	} while (next_permutation(ls.begin(), ls.end()));
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	ofstream fout;
	fout.open("result.txt");
	int t;
	cin >> t;
	for (int i = 1; i <= 10; i++) ls.push_back(i);
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i < n-1; i++) cin >> node[i].first >> node[i].second;
		BT();
		for (int i = 0; i < n; i++) fout << ans[i] << ' ';
		fout << '\n';
	}
	fout.close();
}
// 출력결과를 Text로 제출함