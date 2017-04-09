//
//  main.cpp
//  Rotate List
//
//  Created by Rencheng Tan on 5/18/16.
//  Copyright © 2016 Rencheng Tan. All rights reserved.
//

#include <iostream>
#include "ListNode.h"
using namespace std;

ListNode* rotateRight(ListNode* head, int k);

int main(int argc, const char * argv[]) {
    // insert code here...
    ListNode a(1);
    a.next = new ListNode(2);
    a.next->next =new ListNode(3);
    ListNode* res = rotateRight(&a, 200000);
    return 0;
}
ListNode* rotateRight(ListNode* head, int k) {
    if(head == NULL || head->next == NULL || k == 0)
        return head;
    
    ListNode* left = head;
    ListNode* right = head, *res = NULL;
    int len = 1;
    while(right->next)
    {
        right = right->next;
        len++;
    }
    k = k % len;
    right = head;
    
    if(k == 0)
        return head;
    for(int i = 0;i < len-k-1; i++)
    {
        if(right->next)
            right = right->next;
        else
            return head;
    }
    left = right;
    
    while(right->next)
        right= right -> next;
    res = left->next;
    left->next = NULL;
    right->next = head;
    return res;
}