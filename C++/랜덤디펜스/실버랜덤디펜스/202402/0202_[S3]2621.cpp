#include <iostream>
#include <utility>
using namespace std;

int color[26], number[10];

bool define_flush(int c) {
    return color[c] == 5;
}

bool define_straight() {
    for (int idx = 1; idx <= 9; idx++) {
        if (number[idx] == 1) {
            for (int j = 1; j < 5; j++) {
                if (number[idx + j] != 1) {
                    return false;
                }
            }
            return true;
        }
    }
    return true;
}

int define_index(int num) {
    for (int i = 1; i < 10; i++) {
        if (number[i] == num) return i;
    }
}

int samenum() {
    int r = 0;
    for (int i = 1; i < 10; i++) {
        r = max(r, number[i]);
    }
    return r;
}

int calc() {
    int mx = -1, idx, ans = 0;
    for (int j = 9; j >= 0; j--) {
        if (number[j] >= 1) mx = max(mx, j);
    }

    for (int i = 0; i < 26; i++) {
        if (define_flush(i)) {
            if (define_straight()) {
                ans = max(ans, 900 + mx);
            }
            else {
                ans = max(ans, 600 + mx);
            }
        }
    }
    if (define_straight()) ans = max(ans, 500 + mx);
    switch (samenum()) {
    case 4:
        ans = max(ans, 800 + define_index(4));
        break;
    case 3:
        idx = define_index(3);
        for (int i = 1; i < 10; i++) {
            if (number[i] == 2) {
                ans = max(ans, 700 + 10 * idx + i);
            }
        }
        ans = max(ans, 400 + idx);
        break;
    case 2:
        idx = define_index(2);
        for (int i = idx + 1; i < 10; i++) {
            if (number[i] == 2) {
                ans = max(ans, 300 + 10 * i + idx);
            }
        }
        ans = max(ans, 200 + idx);
        break;
    case 1:
        ans = max(ans, 100 + mx);
        break;
    }
    return ans;
}

int main(void)
{
    for (int i = 0; i < 5; i++) {
        char c; int n;
        cin >> c >> n;
        color[c - 'A']++;
        number[n]++;
    }
    int score = calc();
    cout << score;
    return 0;
}