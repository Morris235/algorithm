//
//  main.cpp
//  10430
//
//  Created by Morris Lee on 1/5/24.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int A = 2, B = 2, C = 2;
    cin >> A >> B >> C;
    cout <<  (A+B)%C << endl;
    cout <<  ((A%C) + (B%C))%C << endl;
    cout << (A*B)%C << endl;
    cout << ((A%C) * (B%C))%C << endl;
    return 0;
}
