#include<iostream>
#include<string>
#include<algorithm>
#include<sstream>
#include<vector>
using namespace std;
string str, trump;
vector<string> trumpvec, result;
int ctoi(char c) {
	if (c >= '0' && c <= '9') return c - '0';
	else return c - 'a' + 10;
}
int priority(string str) {
	string t1 = str.substr(0, 2), t2 = str.substr(2);
	if (abs(ctoi(t1[0]) - ctoi(t2[0])) == 1 || abs(ctoi(t1[0]) - ctoi(t2[0])) == 14) return 1;
	else if (ctoi(t1[0]) == ctoi(t2[0])) return 2;
	else return 3;
}
bool samecolor(string str) {
	string t1 = str.substr(0, 2), t2 = str.substr(2);
	return t1[1] == t2[1];
}
int greaternum(string str) {
	string t1 = str.substr(0, 2), t2 = str.substr(2);
	return max(ctoi(t1[0]), ctoi(t2[0]));
}
int lessnum(string str) {
	string t1 = str.substr(0, 2), t2 = str.substr(2);
	return min(ctoi(t1[0]), ctoi(t2[0]));
}

char greatercolor(string str) {
	string t1 = str.substr(0, 2), t2 = str.substr(2);
	if (ctoi(t1[0]) > ctoi(t2[0])) return t1[1];
	else return t2[1];
}

bool trumpsort(string trump1, string trump2) {
	if (priority(trump1) != priority(trump2)) return priority(trump1) < priority(trump2);
	else {
		if (samecolor(trump1) != samecolor(trump2)) return samecolor(trump1) > samecolor(trump2);
		if (greaternum(trump1) != greaternum(trump2)) return greaternum(trump1) > greaternum(trump2);
		if (lessnum(trump1) != lessnum(trump2)) return lessnum(trump1) > lessnum(trump2);
		return greatercolor(trump1) < greatercolor(trump2);
	}
}
int main() {
	getline(cin, str);
	stringstream ss(str);
	while (getline(ss, trump, ',')) {
		trumpvec.push_back(trump);
	}
	int tsize = (int)trumpvec.size();
	for (int i = 0; i < tsize; i++) {
		for (int j = i + 1; j < tsize; j++) {
			result.push_back(trumpvec[i] + trumpvec[j]);
		}
	}
	sort(result.begin(), result.end(), trumpsort);
	for (string str : result) cout << str << '\n';
}