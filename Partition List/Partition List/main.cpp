//
//  main.cpp
//  Partition List
//
//  Created by Rencheng Tan on 1/15/16.
//  Copyright © 2016 Rencheng Tan. All rights reserved.
//

#include <iostream>
#include "ListNode.h"
using namespace std;
ListNode* partition(ListNode* head, int x);

int main(int argc, const char * argv[]) {
    // insert code here...
    ListNode * a = new ListNode (2);
    a->next = new ListNode(1);
    //a->next->next = new  ListNode(2);
    ListNode * b = partition(a, 2);
    cout << b->val << endl;
}

    ListNode* partition(ListNode* head, int x) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode * pre = head;
        ListNode* cur = head;
        ListNode* Head = new ListNode(-1);
        ListNode* newcur = Head;
        while(cur)
        {
            if(pre->val < x)
            {
                cur = cur->next;
                pre->next = NULL;
                newcur->next = pre;
                newcur = newcur->next;
                pre = cur;
            }
            else
            {
                cur = cur -> next;
                pre = cur;
            }
        }
        ListNode * pre1 = head;
        ListNode* cur1 = head;
        while(cur1)
        {
            if(pre1->val >= x)
            {
                
                cur1 = cur1->next;
                pre1->next = NULL;
                newcur->next = pre1;
                newcur = newcur->next;
                pre1 = cur1;
            }
            else
            {
                cur1 = cur1 -> next;
                pre1 = cur1;
            }
        }
        return Head->next;
    }