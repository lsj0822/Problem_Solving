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
		//spPos�� ���� ������ ����ϴ� �迭
		spPos[a]++;
		spPos[b]--;
	}
	for (int i = 0; i <= 1000000; i++) {
		//�� ��ǥ���� ��� ���� �����ִ� ���� ���
		addedNum += spPos[i];
		Pos[i] = addedNum;
	}
	//��������
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