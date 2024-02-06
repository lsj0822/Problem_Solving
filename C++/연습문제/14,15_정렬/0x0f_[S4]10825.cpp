#include <bits/stdc++.h>
using namespace std;

int n;
tuple<string, int, int, int> score[100005];

bool scoresort(tuple<string, int, int, int> a, tuple<string, int, int, int> b) {
	if (get<1>(a) != get<1>(b)) return get<1>(a) > get<1>(b);
	else if (get<2>(a) != get<2>(b)) return get<2>(a) < get<2>(b);
	else if (get<3>(a) != get<3>(b)) return get<3>(a) > get<3>(b);
	else return get<0>(a) < get<0>(b);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string name;
		int score1, score2, score3;
		cin >> name >> score1 >> score2 >> score3;
		score[i] = {name, score1, score2, score3 };
	}
	sort(&score[0], &score[n], scoresort);
	for (int i = 0; i < n; i++) {
		cout << get<0>(score[i]) << '\n';
	}
}