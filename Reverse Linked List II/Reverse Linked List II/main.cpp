//
//  main.cpp
//  Reverse Linked List II
//
//  Created by Rencheng Tan on 2/22/16.
//  Copyright © 2016 Rencheng Tan. All rights reserved.
//

#include <iostream>
#include "ListNode.h"

using namespace std;
ListNode* reverseBetween(ListNode* head, int m, int n);

int main(int argc, const char * argv[]) {
    // insert code here...
    //std::cout << "Hello, World!\n";
    ListNode *a = new ListNode(1);
    a->next = new ListNode(2);
    a->next->next = new ListNode(3);
    a->next->next->next = new ListNode(4);
    ListNode* head = reverseBetween(a, 2, 4);
    cout << head->val << head -> next -> val << endl;
    
    return 0;
}
ListNode* reverseBetween(ListNode* head, int m, int n) {
    
    if(head==NULL || head->next==NULL || m == n || m == n-1)
        return head;
    
    ListNode *pre = head;
    ListNode *p = head->next;
    pre->next = NULL;
    ListNode *nxt;
    int count = 1;
    while(p!=NULL) {
        ListNode * begin;
        ListNode * end;
        if (count == m-1) {
            begin = pre;
        }
        if (count == n+1)
            end = pre;
        if(count >= m && count <= n)
        {
            nxt = p->next;
            p->next = pre;
            pre = p;
            p = nxt;
        }
        else
        {
            count ++;
            pre = p;
            p = p->next;
        }
        
    }
    return pre;
}