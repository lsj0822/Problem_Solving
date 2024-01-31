#include<iostream>
#include<vector>

using namespace std;
int n, m;
vector<int> V;
int vst[10], board[10];
void bt() {
	if (V.size() == m) {
		for (int v : V) {
			cout << v << " ";
		}
		cout << '\n';
	}
	else {
		for (int i = 1; i <= n; i++) {
			if (!vst[i]) {
				vst[i] = 1;
				V.push_back(i);
				bt();
				V.pop_back();
				vst[i] = 0;
			}
		}
	}

}
int main() {
	cin >> n >>  m;
	bt();
}