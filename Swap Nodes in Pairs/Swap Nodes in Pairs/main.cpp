//
//  main.cpp
//  Swap Nodes in Pairs
//
//  Created by Rencheng Tan on 1/28/16.
//  Copyright © 2016 Rencheng Tan. All rights reserved.
//

#include <iostream>
#include "ListNode.h"
using namespace std;
ListNode* swapPairs(ListNode* head);

int main(int argc, const char * argv[]) {
    // insert code here...
    ListNode *a = new ListNode(1);
    a->next = new ListNode(2);
    ListNode *result = swapPairs(a);
    cout << result->val << result->next->val << endl;
    return 0;
}
ListNode* swapPairs(ListNode* head) {
    if(!head || !head->next)
        return head;
    ListNode * Head = new ListNode(0);
    ListNode * temp = Head;
    ListNode * cur = head;
    ListNode * pre = head;
    //ListNode * res = tem;
    while(cur && cur->next)
    {
        temp->next = cur ->next;
        pre = cur->next->next;
        temp->next->next = cur;
        cur->next = NULL;
        temp = temp->next->next;
        cur = pre;
    }
    if(cur)
        temp->next = cur;
    return Head->next;
    
}