#include <iostream>
#include <queue>
using namespace std;

int trial;

int main(void)
{
    cin >> trial;
    for (int t = 0; t < trial; t++) {
        int n, idx = 0;
        long long p[300], res[300];
        queue<long long> Q;
        cin >> n;
        for (int i = 0; i < 2 * n; i++) {
            cin >> p[i];
        }
        for (int i = 0; i < 2 * n; i++) {
            if (Q.empty()) Q.push(p[i]);
            else {
                if (Q.front() * 4 / 3 == p[i]) {
                    res[idx++] = p[i];
                    Q.pop();
                }
                else {
                    Q.push(p[i]);
                }
            }
        }
        cout << "Case #" << t + 1 << ": ";
        for (int i = 0; i < n; i++) {
            cout << res[i] * 3 / 4 << " ";
        }
        cout << "\n";
    }
    return 0;
}