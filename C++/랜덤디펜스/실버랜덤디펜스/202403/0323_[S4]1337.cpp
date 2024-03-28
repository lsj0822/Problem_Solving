#include <iostream>
#include <algorithm>
using namespace std;

int n, arr[55], ans = 0;

int main(void)
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n; i++) {
        int tmp = 1;
        for (int d = 1; d <= 4; d++) if (find(&arr[0], &arr[n], arr[i] + d) != &arr[n]) tmp++;
        ans = max(ans, tmp);
    }
    cout << max(5 - ans, 0);
    return 0;
}