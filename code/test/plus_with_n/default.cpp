// Created on iPad.

#include <iostream>
using namespace std;

// 더하기 연산이 n번 발생한다.
// 선형시간의 계산 O(n)
void cal1()
{
    int N, res = 0;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        res += i;
    }
    cout << "O(n)" << res << "\n";
}

// N이 얼마나 크게 입력 되어도 "더하기", "곱하기", "나누기" 총 세번만 발생한다.
// 상수시간의 계산 O(1)
void cal2()
{
    int N, res = 0;
    cin >> N;
    res = N * (N + 1) / 2;
    cout << "O(1) : " << res << "\n";
}

int main()
{
    cal2();
    return 0;
}