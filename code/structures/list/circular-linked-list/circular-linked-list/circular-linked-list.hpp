#ifndef CIRCULAR_LINKE_LIST
#define CIRCULAR_LINKE_LIST

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct TagNode
{   
    ElementType data;
    struct TagNode* prevNode;
    struct TagNode* nextNode;
} Node;

Node* CllCreateNode(ElementType newData);
void CllDestroyNode(Node* node);
void CllAppendNode(Node** head, Node* newNode);
void CllInsertAfter(Node* current, Node* newNode);
void CllInsertBefore(Node** head, Node* current, Node* newHead);
void CllInsertNewHead(Node** head, Node* newHead);
void CllRemoveNode(Node** head, Node* remove);
Node* CllGetNodeAt(Node* head, int location);
int CllGetNodeCount(Node* head);
void CllDestroyAllNodes(Node** list);
void PrintReverse(Node* head);

#endif /* CIRCULAR_LINKE_LIST */
