//
//  main.cpp
//  Remove Linked List Elements
//
//  Created by Rencheng Tan on 1/7/16.
//  Copyright © 2016 Rencheng Tan. All rights reserved.
//

#include <iostream>
#include <iostream>
#include "ListNode.h"
using namespace std;
ListNode* removeElements(ListNode* head, int val);

int main(int argc, const char * argv[]) {
    // insert code here...
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    //head->next->next = new  ListNode(2);
    //head->next->next->next = new  ListNode(1);
    ListNode* newhead =  removeElements(head,1);
    cout << newhead->next->val << endl;
    return 0;
}
ListNode* removeElements(ListNode* head, int val) {
    if(head == NULL)
        return head;
    ListNode* pre = head;
    ListNode* cur = head;
    while(cur)
    {
        cur = cur -> next;
        if(pre->val == val)
        {
            head = cur;
            pre = cur;
            continue;
        }
        if(cur && cur->val == val)
            pre->next = cur->next;
        else
            pre = cur;

    }
    return head;
}
