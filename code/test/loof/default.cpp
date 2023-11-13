// Created on iPad.

#include <iostream>
using namespace std;

// 함수는 메인함수보다 먼저 정의 되어야 한다. js 처럼 호이스팅이 되지 않는다.
// 하지만 함수 프로토타입을 선언하면 main뒤에 함수를 정의하는게 가능하다.
// 대규모 코드 작성시에 유리하다.

void forSentence();
void whileSentence();
void doWhileSentence();
void morseCode();

// 함수를 자주 호출하면 속도가 느려이수 있지만 inline 함수의 경우 일반적인 함수 호출의 과정을 거치지 않고
// 함수의 모든 코드를 호출된 자리에 바로 삽입하는 방식의 함수다.
// 하지만 함수 내용이 길면 컴파일러가 inline으로 인정을 안할수 있라며 가독성도 좋지 않다.
inline int sum(int x, int y) {return x+y;};

int main() {
    // int num1,num2 = 0;
    // cout << "첫번째 숫자를 입력하세요\n";
    // cin >> num1;
    // cout << "두번째 숫자를 입력하세요\n";
    // cin >> num2;
    // cout << num1 << " + " << num2 << " = " << sum(num1, num2) << " 입니다.\n";
    forSentence();
    return 0;
}

void forSentence()
{
    int num = 0;
    int result = 0;
    cout << "반복하여 더하기할 숫자를 입력하세요 (for)";
    cin >> num;
    for (int i =0; i <= num; i++) {
        result += i;
    }
    cout << result << "\n";
}

void whileSentence() 
{
    int result = 0;
    int i = 0;
    int limit = 0;
    cout << "반복하여 더하기할 숫자를 입력하세요 (while) \n";
    cin >> limit;
    while(i < limit) {
        i++;
        result += i; 
    }
    cout << result << "\n";
}

void doWhileSentence() {
    int i = 0;
    int limit = 0;
    cout << "반복할 숫자를 입력하세요 (do~while) \n";
    cin >> limit;
    do {
        cout << i++ << "번째 반복입니다. \n";
    }while(i <= limit);
}

void morseCode() {
    int repit = 5;
    int morseLen = 7;
    int morse = 0;
    for (int i = 0; i < repit; i++) {
        for (int j = 0; j < morseLen; j++) {
            if (morse == 0) {
                cout << "-";
                morse = 1;
            } else {
                cout << "*";
                morse = 0;
            }
        }
        cout << "\n";
    }
}