#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
//举个例子来看， 1- 5000, 这里看的时候分奇数长度的回文和偶数长度的回文
//对于奇数长度的回文来说，回文节的范围是1-99
//对于偶数长度的回文来说，回文节范围是1-50
//再举个例子，1-500
//奇数，1-50
//偶数，1-9
//再举个例子，1-50000
//奇数，1-500
//偶数，1-99

//但是如果是5-500的话，注意回文节最小还是1，比如11
//最小范围还没找到比较好的算法，姑且都从1开始------懒！

int odd_max, even_max;

int getMaxRange(int n)
{
    int tmp = 0;
    int N = n;
    while (n > 0) {
        tmp += 1;
        if (!(tmp % 2)) {
            N = N / 10;
        }
        n /= 10;
    }
    if (!(tmp % 2)) { //如果最大值是偶数长度 根据上面的说明找规律就是了
        even_max = N;
        odd_max = 1;
        for (int i = 0; i < tmp / 2; i++) {
            odd_max *= 10;
        }
        odd_max--; //比如99 999等
    } else {
        odd_max = N;
        even_max = 1;
        for (int i = 0; i < tmp / 2; i++) {
            even_max *= 10;
        }
        even_max--; //同上
    }
    return N;
}

int getPalindromeOdd(int num) //创建奇数长度回文
{
    int N = num;
    N = N / 10;
    while (N > 0) {
        num *= 10;
        num += N % 10;
        N /= 10;
    }
    return num;
}

int getPalindromeEven(int num) //创建偶数长度
{
    int N = num;
    while (N > 0) {
        num *= 10;
        num += N % 10;
        N /= 10;
    }
    return num;
}

bool isPrime(int num)
{
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main()
{
    int a, b;
    vector<int> result;
    cin >> a >> b;
    getMaxRange(b);
    for (int i = 1; i <= even_max; i++) {
        int even = getPalindromeEven(i);
        if (even >= a && even <= b && isPrime(even)) {
            result.push_back(even);
        }
    }
    for (int i = 1; i <= odd_max; i++) {
        int odd = getPalindromeOdd(i);
        if (odd >= a && odd <= b && isPrime(odd)) {
            result.push_back(odd);
        }
    }
    sort(result.begin(), result.end());
    for (auto i = result.begin(); i != result.end(); i++) {
        cout << *i << endl;
    }
    system("pause");
    return 0;
}