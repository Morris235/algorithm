// Created on iPad.

#include <iostream>
using namespace std;

int main() {
    int a = 5;
    int* pA = &a;

    cout << "a의 값은 " << a << " 이다\n" ;
    cout << "a의 메모리 주소값은 " << &a << " 이다\n" ;
    cout << "pA의 값은 " << pA << " 이다\n" ;
    cout << "pA가 가리키는 변수의 값은 " << *pA << " 이다\n" ;
    cout << "\n";
    int b = 10;
    *pA = 10;
    cout << "b의 값은 " << b << " 이다\n" ;
    cout << "pA가 가리키는 변수의 값은 " << *pA << " 이다\n" ;
    return 0;
}