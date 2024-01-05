//
//  linked-list-stack.hpp
//  linked-list-stack
//
//  Created by Morris Lee on 12/27/23.
//

#ifndef linked_list_stack_hpp
#define linked_list_stack_hpp

#include <stdio.h>

typedef struct tagNode
{
    char* data;
    struct tagNode* nextNode;
} Node;

typedef struct tagLinkedListStack {
    Node* list;
    Node* top;
} LinkedListStack;

void LLSCreateStack(LinkedListStack** stack);
void LLSDestroyStack(LinkedListStack* stack);

Node* LLSCreateNode(char* data);
void LLSDestroyNode(Node* _node);

void LLSPush(LinkedListStack* stack, Node* newNode);
Node* LLSPop(LinkedListStack* stack);

Node* LLSTop(LinkedListStack* stack);
int LLSGetSize(LinkedListStack* stack);
int LLSIsEmpty(LinkedListStack* stack);

#endif /* linked_list_stack_hpp */
