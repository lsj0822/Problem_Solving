#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

map<string, int> army;
int n, wmin = 1000000, wmax = -1;
int workhour[4] = { 4,6,4,10 };
int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int w = 0; w < n; w++) {
        for (int h = 0; h < 4; h++) {
            for (int d = 0; d < 7; d++) {
                string str;
                cin >> str;
                if (str != "-") {
                    army[str] += workhour[h];
                }
            }
        }
    }
    for (auto it = army.begin(); it != army.end(); it++) {
        wmin = min(wmin, it->second);
        wmax = max(wmax, it->second);
    }
    if (wmax - wmin > 12) cout << "No";
    else cout << "Yes";
    return 0;
}