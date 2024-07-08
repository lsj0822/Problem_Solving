//#include<iostream>
//#include<string>
//#include<algorithm>
//using namespace std;
//string words[300005], board[4];
//const int MX = 2400005, ROOT = 1;
//int w, b, unused = 2;
//int nxt[MX][26];
//int dx[8] = { 0,-1,-1,-1,0,1,1,1 }, dy[8] = { -1,-1,0,1,1,1,0,-1 }, score[9] = { 0,0,0,1,1,2,3,5,11 };
//bool vst[4][4], chk[MX];
//int c2i(char c) {
//	return c - 'A';
//}
//bool word_sort(string a, string b) {
//	if (a.size() != b.size()) return a.size() > b.size();
//	else return a < b;
//}
//int main() {
//	cin >> w;
//	for (int i = 0; i < w; i++) cin >> words[i];
//	sort(&words[0], &words[w], word_sort);
//	for (int i = 0; i < w; i++) {
//		int cur = ROOT;
//		for (char c : words[i]) {
//			if (nxt[cur][c2i(c)] == -1) nxt[cur][c2i(c)] = unused++;
//			cur = nxt[cur][c2i(c)];
//		}
//		chk[cur] = 1;
//	}
//	cin >> b;
//	while (b--) {
//		string ans;
//		fill(&nxt[0][0], &nxt[MX - 1][0], -1);
//		for (int i = 0; i < 4; i++) cin >> board[i];
//		for (int i = 0; i < w; i++) {
//			char srt = words[i][0];
//			for (int x = 0; x < 4; x++) {
//				for (int y = 0; y < 4; y++) {
//					if (board[x][y] == srt) bt(x, y, 0);
//				}
//			}
//		}
//	}
//}