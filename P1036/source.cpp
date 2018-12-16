#include <iostream>
#include <math.h>
using namespace std;

int nums[21];
int n, cnt, k;

bool isPrime(int num)
{
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

void calculate(int start, int num, int total) //start表示从哪开始 num表示是第几个数字 total是目前为止的和
{
    int i;
    if (num == k) {
        for (i = start; i < n; i++) {
            if (isPrime(total + nums[i])) {
                cnt++;
            }
        }
        return;
    }
    for (i = start; i < n - (k - num); i++) {
        calculate(i + 1, num + 1, total + nums[i]);
    }
}

int main()
{
    int i;
    cin >> n >> k;
    k--;
    for (i = 0; i < n; i++) {
        cin >> nums[i];
    }
    calculate(0, 0, 0);
    cout << cnt;
    system("pause");
    return 0;
}