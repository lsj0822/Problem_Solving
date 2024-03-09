#include <iostream>
#include <string>
using namespace std;
int sp, board[26];
string str, ans;
int main(void)
{
    getline(cin, str);
    cin >> sp;
    for (int i = 0; i < 26; i++) cin >> board[i];
    char ls = str[0];
    int stdix = tolower(ls) - 'a';
    ans += toupper(ls);
    board[stdix] -= 2;
    for (int i = 1; i < str.length(); i++) {
        if (str[i] != ls) {
            if (ls == ' ') {
                board[tolower(str[i]) - 'a']--;
                ans += toupper(str[i]);
            }
            if (str[i] == ' ') {
                sp--;
            }
            else {
                int idx = tolower(str[i]) - 'a';
                board[idx]--;
            }
            ls = str[i];
        }
    }
    if (sp < 0) {
        cout << -1;
        return 0;
    }
    for (int i = 0; i < 26; i++) {
        if (board[i] < 0) {
            cout << -1;
            return 0;
        }
    }
    cout << ans;
    return 0;
}