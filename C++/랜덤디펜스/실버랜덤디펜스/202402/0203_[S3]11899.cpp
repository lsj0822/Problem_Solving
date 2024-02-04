#include <iostream>
#include <string>
#include <stack>
using namespace std;

string str;
int ans = 0;

int main(void)
{
    getline(cin, str);
    stack<char> ST;
    for (auto c : str) {
        if (c == '(') ST.push(c);
        else {
            if (!ST.size()) {
                ans++;
                continue;
            }
            if (ST.top() == ')') ST.push(c);
            else if (ST.top() == '(') ST.pop();
        }
    }
    cout << ans + ST.size();
    return 0;
}