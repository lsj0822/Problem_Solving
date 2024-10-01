#include<iostream>
#include<cctype>
#include<string>
#include<algorithm>
using namespace std;

int alpha[26] = { 1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10 };
int wboard[15][15], lboard[15][15];
void boardcpy() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			wboard[14 - i][j] = wboard[i][j];
			wboard[i][14 - j] = wboard[i][j];
			wboard[14 - i][14 - j] = wboard[i][j];

			lboard[14 - i][j] = lboard[i][j];
			lboard[i][14 - j] = lboard[i][j];
			lboard[14 - i][14 - j] = lboard[i][j];
		}
	}
}

int scrabble(int x, int y, int axis, string word) {
	int score = 0, multiple = 1;
	for (int i = 0; i < word.length(); i++) {
		int nx = x + (axis == 0) * i, ny = y + (axis == 1) * i;
		score += alpha[word[i] - 'A'] * lboard[nx][ny];
		multiple *= wboard[nx][ny];
	}
	return score * multiple;
}
int main() {
	fill(&lboard[0][0], &lboard[8][8], 1);
	fill(&wboard[0][0], &wboard[8][8], 1);
	wboard[0][0] = 3; wboard[7][0] = 3; wboard[0][7] = 3; wboard[7][7] = 2;
	for (int i = 1; i <= 4; i++) wboard[i][i] = 2;
	lboard[0][3] = lboard[3][0] = 2; lboard[1][5] = lboard[5][1] = 3;
	lboard[2][6] = lboard[6][2] = 2; lboard[3][7] = lboard[7][3] = 2;
	lboard[5][5] = 3; lboard[6][6] = 2;
	boardcpy();
	while (1) {
		string pos, words;
		int posX, posY, axis;
		cin >> pos;
		if (pos == "#") return 0;
		cin >> words;
		if (isdigit(pos[0])) {
			axis = 1;
			posX = stoi(pos.substr(0, pos.length() - 1)) - 1;
			posY = pos[pos.length() - 1] - 'A';
		}
		else {
			axis = 0;
			posX = stoi(pos.substr(1)) - 1;
			posY = pos[0] - 'A';
		}
		cout << pos << ' ' << words << ' ' << scrabble(posX, posY, axis, words) << '\n';
	}
}