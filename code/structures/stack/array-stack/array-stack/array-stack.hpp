//
//  array-stack.hpp
//  array-stack
//
//  Created by Morris Lee on 12/26/23.
//

#ifndef array_stack_hpp
#define array_stack_hpp

#include <stdio.h>

typedef int ElementType;

typedef struct tagNode
{
    ElementType data;
} Node;

typedef struct tagArrayStack
{
    int capacity;
    int top;
    Node* nodes;
} ArrayStack;

void AsCreateStack(ArrayStack** stack, int capacity);
void AsDestroyStack(ArrayStack* stack);
void AsPush(ArrayStack* stack, ElementType data);
ElementType AsPop(ArrayStack* stack);
ElementType AsTop(ArrayStack* stack);
int AsGetSize(ArrayStack* stack);
int AsIsEmpty(ArrayStack* stack);
int AsIsFull(ArrayStack* stack);

#endif /* array_stack_hpp */
