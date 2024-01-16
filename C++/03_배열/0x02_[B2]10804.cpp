#include<bits/stdc++.h>

using namespace std;

int main() {
	vector<int> card(21);
	for (int i = 1; i < 21; i++) {
		card[i] = i;
	}

	for (int i = 0; i < 10; i++) {
		int S, E, length;
		cin >> S >> E;
		length = E - S + 1;
		vector<int> reversecard(length);
		for (int j = 0; j < length; j++) {
			reversecard[j] = card[E - j];
		}
		for (int j = 0; j < length; j++) {
			card[S + j] = reversecard[j];
		}
	}
	for (int i = 1; i < 21; i++) {
		cout << card[i] << " ";
	}
}