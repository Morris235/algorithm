#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "circular-linked-list.hpp"
using namespace std;

Node* CllCreateNode(ElementType newData)
{
    Node* newNode = new Node;
    
    newNode->data = newData;
    newNode->prevNode = NULL;
    newNode->nextNode = NULL;
    
    return newNode;
};

void CllDestroyNode(Node* Node)
{
    delete Node;
};

void CllAppendNode(Node** head, Node* newNode)
{
    if ( (*head) == NULL )
    {
        *head = newNode;
        (*head)->nextNode = *head;
        (*head)->prevNode = *head;
    }
    else
    {
        // 테일과 헤드 사이에 newNode를 삽입
        Node* tail = (*head)->prevNode;
        
        tail->nextNode->prevNode = newNode; // 헤드의 prevNode를 newNode로 설정
        tail->nextNode = newNode; // 테일의 다음 노드를 새로운 노드로 설정
        
        newNode->nextNode = (*head);
        newNode->prevNode = tail; // 새로운 테일의 prevNode가 기존의 테일을 가리킴
    }
};

Node* CllGetNodeAt(Node* head, int location)
{
    Node* currentNode = head;
    while (currentNode != NULL && (--location) >= 0) {
        currentNode = currentNode->nextNode;
    }
    
    return currentNode;
};

// 리스트 연결을 끊는 작업
void CllRemoveNode(Node** head, Node* remove)
{
    if (*head == remove)
    {
        // remove 노드를 건너뛰고 list를 연결
        (*head)->prevNode->nextNode = remove->nextNode;
        (*head)->nextNode->prevNode = remove->prevNode;
        
        *head = remove->nextNode;
        
        remove->prevNode = NULL;
        remove->nextNode = NULL;
    }
    else
    {
        remove->prevNode->nextNode = remove->nextNode; // remove의 이전노드가 가리키는 다음 노드를 remove의 다음 노드를 가리키도록 설정
        remove->nextNode->prevNode = remove->prevNode;
        
        remove->prevNode = NULL;
        remove->nextNode = NULL;
    }
};

void CllInsertAfter(Node* currentNode, Node* newNode)
{
    newNode -> prevNode = currentNode;
    newNode -> nextNode = currentNode -> nextNode;
    
    if (currentNode->nextNode != NULL)
        currentNode -> nextNode -> prevNode = newNode;
    
    // currentNode가 새 노드일때는 무조건 nextNode에 newNode를 추가한다. 책에선 if문 안에 들어가 있지만 이는 잘 못된 내용이다.
    currentNode -> nextNode = newNode;
};

// 노드를 삽입/삭제할때 노드(구조체)에 번호를 매겨서 전체 리스트의 길이를 알 수 있게 한다.
int CllGetNodeCount(Node* head)
{
    unsigned int count = 0;
    Node* currentNode = head;
    while (currentNode != NULL) {
        currentNode = currentNode ->nextNode;
        count++;
    }
    return count;
};

void CllInsertBefore(Node** head, Node* currentNode, Node* newHead)
{
    // 헤드 앞에 새로운 노드를 추가할 경우
    if (*head !=NULL && *head == currentNode)
    {
        newHead -> nextNode = currentNode;
        newHead -> prevNode = NULL;
        currentNode -> prevNode = newHead;
        *head = newHead;
    }
    // currentNode 앞으로 새로운 노드를 추가할 경우
    else
    {
        newHead -> prevNode = currentNode -> prevNode;
        if (currentNode->prevNode != NULL) // currentNode가 첫번째 노드가 아닌지 확인. * GPT 리뷰 수정 사항
            currentNode->prevNode->nextNode = newHead;
        
        currentNode -> prevNode = newHead;
        newHead -> nextNode = currentNode;
    }
};

void CllInsertNewHead(Node** head, Node* newHead)
{
    Node* currentNode = *head;
    newHead -> prevNode = NULL;
    newHead -> nextNode = currentNode;
    
    // 현재 head가 NULL이 아닐때만 이 작업을 수행해야 함. 리스트가 비어있는 경우를 고려해야 한다. *GPT 리뷰 수정사항
    if (currentNode != NULL)
        currentNode -> prevNode = newHead;
    
    *head = newHead;
};

void CllDestroyAllNodes(Node** List)
{
    // 리스트를 순회하면서 포인터의 노드들을 메모리에서 해제하고 마지막에 NULL로 처리해야 한다.
    Node* currentNode = *List;
    Node* NodeToDelete = NULL;
    while (currentNode != NULL)
    {
        NodeToDelete = currentNode; // 임시로 리스트 포인터를 저장
        currentNode = currentNode -> nextNode; // 노드 이동
        delete NodeToDelete; // 첫번째 노드부터 메모리 해제, 이후 노드이동을 하면서 순차적으로 메모리 해제
    }
    *List = NULL;
};

void PrintReverse(Node* head)
{
    if (head == NULL) return;
    Node* tail = head->prevNode;
    
    // head를 출력하기 전에 tail이 head로 이동하면서 종료 된다.
    //    while (tail != head)
    //    {
    //        cout << tail -> data << endl;
    //        tail = tail -> prevNode;
    //    }
    
    // * GPT 수정사항
    do {
        cout << tail -> data << endl;
        tail = tail -> prevNode;
    } while (tail != head -> prevNode); // 처음 시작한 노드로 돌아올 때까지 반복
};
