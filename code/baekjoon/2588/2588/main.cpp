//
//  main.cpp
//  2588
//
//  Created by Morris Lee on 1/5/24.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int operand1 = 0, operand2 = 0;
    cin >> operand1;
    cin >> operand2;
    int operand2Copy = operand2;
    // 방법은 알았는데 구현을 블로그의 도움을 받음 : 숫자를 각 자리마다 반환받는 방법 (산수 원리에 대한 이해 부족)
    while(operand2 > 0)
    {
        int digit = operand2 % 10;
        operand2/=10;
        cout << operand1 * digit << endl;
    }
    cout << operand1 * operand2Copy << endl;
    return 0;
}

// 다른 풀이 1
//int A, B;
//scanf("%d %d", &A, &B);
//printf("%d\n%d\n%d\n%d", A*(B%10), A*(B%100 / 10), A*(B/100), A*B);

// 다른 풀이 2
//int a;
//char b[4];
//
//cin >> a;
//cin >> b;
//
//int one = a * (b[2] - '0');
//int two = a * (b[1] - '0');
//int thr = a * (b[0] - '0');
//int fin = a * atoi(b);
//
//
//cout << one << endl << two << endl << thr << endl << fin;

// 다른 풀이 3
//#include <iostream>
//
//using namespace std;
//int main()
//{
//    int a, b = 0;
//    cin >> a >> b ;
//    cout << a * (b%10) << endl;
//    cout << a * (b%100 /10) << endl;
//    cout << a * (b /100) << endl;
//    cout << a * b << endl;
//}
