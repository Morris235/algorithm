//
//  main.cpp
//  circular-linked-list
//
//  Created by Morris Lee on 12/23/23.
//

#include <iostream>
#include "circular-linked-list.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    
    Node* list = NULL;
    Node* newNode = NULL;
    Node* currentNode = NULL;
    
    CllAppendNode(&list, CllCreateNode(100));
    CllAppendNode(&list, CllCreateNode(120));
    CllAppendNode(&list, CllCreateNode(130));
    
//    newNode = CllCreateNode(515);
//    currentNode = CllGetNodeAt(list, 2);
    
//    CllInsertBefore(&list, currentNode, newNode);
//    CllInsertNewHead(&list, newNode);
//        for (int i = 0; i<CllGetNodeCount(list); i++)
//        {
//            cout << CllGetNodeAt(list, i)->count << endl;
//        }
    
    PrintReverse(list);
    return 0;
}
