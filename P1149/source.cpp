#include <iostream>
using namespace std;

//感觉打表比较简单

int stick[10] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };

int number[25];

int calculateStick(int num)
{
    int cnt = 0;
    if (num == 0)
        return 6;
    while (num > 0) {
        cnt += stick[num % 10];
        num /= 10;
    }
    return cnt;
}

int result[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 8, 9, 6, 9, 29, 39, 38, 65, 88, 128 }; //打表结果

int main()
{
    for (int i = 0; i <= 1111; i++) {
        for (int j = i; j <= 1111; j++) {
            int total = calculateStick(i) + calculateStick(j) + calculateStick(i + j);
            if (total <= 20) {
                if (i != j) {
                    number[total + 4] += 2;
                    /*cout << i
                         << "+"
                         << j
                         << "="
                         << i + j
                         << "(total="
                         << total + 4
                         << ")" << endl;*/
                } else {
                    number[total + 4]++;
                    /*cout << i
                         << "+"
                         << j
                         << "="
                         << i + j
                         << "(total="
                         << total + 4
                         << ")" << endl;*/
                }
            }
        }
    }
    for (int i = 0; i <= 24; i++) {
        cout << "," << number[i];
    }
    system("pause");
    return 0;
}