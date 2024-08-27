#include<iostream>
#include<string>
#include<algorithm>
#include<sstream>
using namespace std;
string n, str, tmp;
int nn, ans;
bool vst[1005];
int main() {
	while (1) {
		fill(&vst[0], &vst[1001], 0);
		ans = 0;
		getline(cin, n);
		if (n == "0") return 0;
		nn = stoi(n);
		getline(cin, str);
		stringstream ss(str);
		while (getline(ss, tmp, ',')) {
			if (tmp.find('-') != string::npos) {
				int st = stoi(tmp.substr(0,tmp.find('-'))), en = stoi(tmp.substr(tmp.find('-') + 1));
				if (st > en) continue;
				for (int i = st; i <= min(en,nn); i++) vst[i] = 1;
			}
			else {
				int page = stoi(tmp);
				if (page <= nn)	vst[page] = 1;
			}
		}
		for (int i = 1; i <= nn; i++) ans += vst[i];
		cout << ans << '\n';
	}
}