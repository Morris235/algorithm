// Created on iPad.

#include <iostream>
using namespace std;

// template : 함수의 인수 타입만 다르고 처리 내용은 같을때 사용, 선언과 동시에 정의해야 한다.
template <class T>
T maxt(T x, T y) {
    if (x > y) {
        return x;
    } else {
        return y;
    }
}

// overload : 함수의 내부 처리 방법이 달라도 관계없는 경우
int min(int x, int y);
double min(double x, double y);

int main() {
    int choice, num1, num2 = 0;
    double num1d, num2d = 0.0;
    const string inputGuide = "첫번째와 두번째 숫자를 입력해주세요 (엔터로 구분)\n";
    cout << "max 구하기 = 1, min(정수) 구하기 = 2, min(실수) 구하기 = 3\n";
    cin >> choice;

    switch(choice) {
        case 1: 
            cout << inputGuide;
            cin >> num1 >> num2;
            cout << "최대값은" << max(num1, num2) << " 입니다.\n";
            break;
        case 2:
            cout << inputGuide;
            cin >> num1 >> num2;
            cout << "최소값은" << min(num1, num2) << " (정수) 입니다.\n";
            break;
        case 3:
            cout << inputGuide;
            cin >> num1d >> num2d;
            cout << "최소값은" << min(num1d, num2d) << " (실수) 입니다.\n";
            break;
        default:
            cout << "입력은 1~3 사이의 숫자만 가능합니다.\n";
            break;
    }
    return 0;
}

int min(int x, int y) {
    if (x < y) {
        return x;
    } else {
        return y;
    }
}

double min(double x, double y) {
    if (x < y) {
        return x;
    } else {
        return y;
    }
}