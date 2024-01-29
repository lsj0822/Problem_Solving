#include<iostream>
#include<vector>
#define X first
#define Y second

using namespace std;
int n, rst = 0;
bool vst1[16], vst2[32], vst3[16];
int queen[16];
void bt(int k) {
	if (k == n) {
		rst++;
		return;
	}
	else {
		for (int i = 1; i <= n; i++) {
			if (!vst1[i] && !vst2[i + k] && !vst3[i - k + n - 1]) {
				queen[k] = i;
				vst1[i] = 1; vst2[i + k] = 1; vst3[i - k + n - 1] = 1;
				bt(k + 1);
				vst1[i] = 0; vst2[i + k] = 0; vst3[i - k + n - 1] = 0;
			}
		}
	}
}

int main() {
	cin >> n;
	bt(0);
	cout << rst;
}