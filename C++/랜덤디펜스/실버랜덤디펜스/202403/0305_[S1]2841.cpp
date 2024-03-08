#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<stack<int>> line(7);
int n, p;
long long ans = 0;
int main(void)
{
    cin >> n >> p;
    while (n--) {
        int ln, pn;
        cin >> ln >> pn;
        if (line[ln].empty()) {
            line[ln].push(pn);
            ans++;
            continue;
        }
        while (!line[ln].empty() && line[ln].top() != pn) {
            if (line[ln].size() == 0 || line[ln].top() < pn) {
                line[ln].push(pn);
                ans++;
            }
            else {
                line[ln].pop();
                ans++;
            }
        }
        if (line[ln].empty()) {
            line[ln].push(pn);
            ans++;
        }
    }
    cout << ans;
    return 0;
}