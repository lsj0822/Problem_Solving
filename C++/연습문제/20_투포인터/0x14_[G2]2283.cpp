#include <iostream>
#include <algorithm>

using namespace std;
int n, k, spPos[1000005], Pos[1000005], addedNum = 0;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		//spPos는 선의 변동을 기록하는 배열
		spPos[a]++;
		spPos[b]--;
	}
	for (int i = 0; i <= 1000000; i++) {
		//각 좌표마다 몇개의 선이 걸쳐있는 지를 기록
		addedNum += spPos[i];
		Pos[i] = addedNum;
	}
	//투포인터
	int en = 0, res = Pos[0];
	for (int st = 0; st <= 1000000; st++) {
		while (en <= 1000000 && res < k) {
			en++;
			if (en != 1000001)res += Pos[en];
		}
		if (en == 1000001) break;
		if (res == k) {
			cout << st << ' ' << en+1;
			return 0;
		}
		res -= Pos[st];
	}
	cout << "0 0";
}