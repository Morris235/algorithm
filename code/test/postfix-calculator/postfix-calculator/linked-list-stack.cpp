#include "cstring"
#include "linked-list-stack.hpp"

void LLSCreateStack(LinkedListStack** stack)
{
    // 스택 구조체를 메모리에 등록, 초기화.
    (*stack) = new LinkedListStack;
    (*stack)->list = NULL;
    (*stack)->top = NULL;
};

void LLSDestroyStack(LinkedListStack* stack)
{
    // 스택이 비었는지 확인하면서 노드 제거
    while(!LLSIsEmpty(stack))
    {
        Node* popped = LLSPop(stack);
        LLSDestroyNode(popped);
    }
    
    delete stack;
};

// 노드를 자유 저장소에 생성할 때 문자열을 저장할 공간도 함께 생성해야 한다
Node* LLSCreateNode(char* newData)
{
    Node* newNode = new Node;
    newNode->data = new char[strlen(newData)+1];
    
    strcpy(newNode->data, newData); // 데이터 저장
    
    newNode->nextNode = NULL; // 다음 노드에 대한 포인터는 NULL로 초기화
    
    return newNode; // 노드의 주소 반환
}

void LLSDestroyNode(Node* _node)
{
    delete _node->data;
    delete _node;
}

void LLSPush(LinkedListStack* stack, Node* newNode)
{
    if (stack->list == NULL)
    {
        stack->list = newNode;
    }
    else
    {
        // 스택의 top에 신규 노드 연결
        stack->top->nextNode = newNode;
    }
    
    // 스택의 top 필드에 새 노드의 주소를 등록
    stack->top = newNode;
}

Node* LLSPop(LinkedListStack* stack)
{
    // LLSPop() 함수가 반환할 최상위 노드 저장
    Node* topNode = stack->top;
    
    if (stack->list == stack->top)
    {
        stack->list = NULL;
        stack->top = NULL;
    }
    else
    {
        // top 아래에 있던 노드를 새로운 currentTop에 저장
        Node* currentTop = stack->list;
        while (currentTop != NULL && currentTop->nextNode != stack->top) {
            currentTop = currentTop->nextNode;
        }
        
        // currentTop을 top에 저장
        stack->top = currentTop;
        stack->top->nextNode = NULL;
    }
    
    return topNode;
}

Node* LLSTop(LinkedListStack* stack)
{
    return stack->top;
}

int LLSGetSize(LinkedListStack* stack)
{
    int count = 0;
    Node* currentNode = stack->list;
    while (currentNode != NULL) {
        currentNode = currentNode->nextNode;
        count++;
    }
    return count;
}

int LLSIsEmpty(LinkedListStack* stack)
{
    return (stack->list == NULL);
}

