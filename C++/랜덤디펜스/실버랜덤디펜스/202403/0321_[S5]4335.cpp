#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> nhigh, nlow;
int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0);
    while (1) {
        int n;
        string detect;
        cin >> n;
        cin.ignore();
        if (!n) return 0;
        getline(cin, detect);
        if (detect == "too high") nhigh.push_back(n);
        else if (detect == "too low") nlow.push_back(n);
        else {
            bool res = true;
            for (auto h : nhigh) if (h <= n) res = false;
            for (auto l : nlow) if (l >= n) res = false;
            if (res) cout << "Stan may be honest\n";
            else cout << "Stan is dishonest\n";
            nhigh.clear(); nlow.clear();
        }
    }
}