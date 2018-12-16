#include <iostream>
using namespace std;

//递推公式 f[n] = f[n / 2] + f[n / 2 - 1] .... + f[2] + f[1] + 1

int f[1001] = { 0, 1, 2 };

int main()
{
    int i, j, k;
    int num;
    cin >> num;
    for (i = 3; i <= num; i++) {
        for (j = i / 2; j > 0; j--) {
            f[i] += f[j];
        }
        f[i]++;
    }
    cout << f[num] << endl;
    return 0;
}