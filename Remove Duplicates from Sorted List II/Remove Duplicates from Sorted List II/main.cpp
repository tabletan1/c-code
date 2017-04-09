//
//  main.cpp
//  Remove Duplicates from Sorted List II
//
//  Created by Rencheng Tan on 1/15/16.
//  Copyright © 2016 Rencheng Tan. All rights reserved.
//

#include <iostream>
#include "ListNode.h"
using namespace std;
ListNode* deleteDuplicates(ListNode* head) ;

int main(int argc, const char * argv[]) {
    // insert code here...
    ListNode * a = new ListNode (1);
    a->next = new ListNode(1);
    a->next->next = new  ListNode(2);
    ListNode * b = deleteDuplicates(a);
    cout << b->val << endl;
    return 0;
}
ListNode* deleteDuplicates(ListNode* head) {
    if(!head || !head ->next)
        return head;
    ListNode * Head = new ListNode(-1);
    Head -> next = head;
    ListNode * pre = Head;
    ListNode * cur = head;
    int flag = 0;
    while (cur)
    {
        while(cur->next && cur ->next->val == cur ->val)
        {
            cur = cur ->next;
            flag = 1;
        }
        if(flag == 1)
        {
            cur = cur -> next;
            flag = 0;
            continue;
        }
        pre ->next = cur;
        pre = pre ->next;
        cur = cur -> next;
        
    }
    pre->next = cur;
    return Head->next;
}