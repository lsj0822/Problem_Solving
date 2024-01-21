#include <bits/stdc++.h>

using namespace std;

int N, M, head, tail, r=0;
int DQ[51];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);

	cin >> N >> M;
	head = 1;
	tail = 0;
	
	for (int i = 0; i <= N; i++) {
		DQ[i] = i;
	}
	

	for(int i = 0; i < M; i++) {
		int k, left = 0, right = 0;
		cin >> k;
		while (tail != k) {
			if (tail == 0) 	tail = N+1;
			tail--;
			if (DQ[tail]) left++;
		}
		while (head != k) {
			head++;
			if (head == N+1) head = 0;
			if (DQ[head]) right++;
		}
		r += min(left, right);
		DQ[k] = 0;
		tail = k;
		head = (k + 1) % (N + 1);
		while (!DQ[head] and i != M-1) {
			head++;
			if (head == N + 1) head = 0;
		}
	}
	cout << r;
}