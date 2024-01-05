//
//  main.cpp
//  linked-list-stack
//
//  Created by Morris Lee on 12/27/23.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#include "linked-list-stack.hpp"

int main(int argc, const char * argv[]) {
    int i = 0;
    int count = 0;
    Node* popped;
    
    LinkedListStack* stack;
    
    LLSCreateStack(&stack);
    
    LLSPush(stack, LLSCreateNode((char*)"abc"));
    LLSPush(stack, LLSCreateNode((char*)"def"));
    LLSPush(stack, LLSCreateNode((char*)"efg"));
    LLSPush(stack, LLSCreateNode((char*)"hij"));
    
    count = LLSGetSize(stack);
    cout << "Size: " << count << ", Top: " << LLSTop(stack)->data << endl;
    cout << endl;
    
    for (i=0; i<count; i++)
    {
        if (LLSIsEmpty(stack))
            break;
        
        popped = LLSPop(stack);
        cout << "Popped: " << popped->data << ", ";
        
        LLSDestroyNode(popped);
        
        if (!LLSIsEmpty(stack))
        {
            cout << "Current Top: " << LLSTop(stack)->data << ", " << endl;
        }
        else
        {
            cout << "Stack is empty" << endl;
        }
    }
    
    LLSDestroyStack(stack);
    return 0;
}
