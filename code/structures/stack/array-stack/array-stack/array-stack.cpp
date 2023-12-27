//
//  array-stack.cpp
//  array-stack
//
//  Created by Morris Lee on 12/26/23.
//

#include "array-stack.hpp"
#include <stdio.h>
#include <stdlib.h>
using namespace std;

void AsCreateStack(ArrayStack** stack, int capacity)
{
    // 스택을 자유 저장소에 생성
    (*stack) = new ArrayStack;
    
    // 입력된 capacity만큼의 노드를 자유 저장소에 생성
    (*stack)->nodes = new Node[capacity];
    
    // capacity 및 top 초기화
    (*stack)->capacity = capacity;
    (*stack)->top = -1;
}

void AsDestroyStack(ArrayStack* stack)
{
    // 노드를 자유 저장소에서 해제
    delete stack->nodes;
    
    // 스택을 자유 저장소에서 해제
    delete stack;
}

void AsPush(ArrayStack* stack, ElementType data)
{
    // 스택이 가득 찼을때 예외처리 필요
    stack->top++;
    stack->nodes[stack->top].data = data;
}

ElementType AsPop(ArrayStack* stack)
{
    // 스택이 비었을때 예외처리 필요
    int position = stack->top--;
    return stack->nodes[position].data;
}

ElementType AsTop(ArrayStack* stack)
{
    return stack->nodes[stack->top].data;
}

int AsGetSize(ArrayStack* stack)
{
    return stack->top+1;
}

int AsIsEmpty(ArrayStack* stack)
{
    return (stack->top == -1);
}

// 스택을 생성할 때 설정한 용량이 가득 찼는지 체크
int AsIsFull(ArrayStack* stack)
{
    return ((stack->top+1) == stack->capacity);
}
