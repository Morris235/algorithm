//
//  main.cpp
//  array-stack
//
//  Created by Morris Lee on 12/26/23.
//

#include <iostream>
#include "array-stack.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    int i = 0;
    ArrayStack* stack = NULL;
    
    AsCreateStack(&stack, 10);
    
    AsPush(stack, 20);
    AsPush(stack, 30);
    AsPush(stack, 40);
    AsPush(stack, 50);
    
    cout << "capacity: " << stack->capacity << ", size: " << AsGetSize(stack) << ", top: " << AsTop(stack) << endl;
    
    cout << "" << endl;
    
    for (i = 0; i<4; i++)
    {
        if(AsIsEmpty(stack))
            break;
        
        cout << "poped: " << AsPop(stack) << " ";
        
        if (!AsIsEmpty(stack))
            cout << "current top: " << AsTop(stack) << endl;
        else
            cout << "stack is Empty" << endl;
    }
    
    AsDestroyStack(stack);
    return 0;
}
