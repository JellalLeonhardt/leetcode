#include <iostream>
using namespace std;

int cnt[26];

int main()
{
    char chr;
    int i, j, max_cnt = 0, LF_cnt = 0;

    while (cin >> noskipws >> chr) {
        if (chr >= 'A' && chr <= 'Z') {
            cnt[chr - 'A']++;
        }
        if (chr == '\n') {
            LF_cnt++;
        }
        if (LF_cnt == 4) {
            break;
        }
    }
    for (i = 0; i < 26; i++) {
        if (cnt[i] > max_cnt) {
            max_cnt = cnt[i];
        }
    }
    for (i = max_cnt; i > 0; i--) {
        for (j = 0; j < 25; j++) {
            if (cnt[j] >= i) {
                cout << "* ";
            } else {
                cout << "  ";
            }
        }
        if (cnt[j] >= i) {
            cout << "*";
        } else {
            cout << " ";
        }
        cout << '\n';
    }
    for (j = 0; j < 25; j++) {
        cout << (char)('A' + j) << ' ';
    }
    cout << 'Z';
    system("pause");
    return 0;
}