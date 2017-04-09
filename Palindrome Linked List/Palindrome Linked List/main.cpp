//
//  main.cpp
//  Palindrome Linked List
//
//  Created by Rencheng Tan on 1/6/16.
//  Copyright © 2016 Rencheng Tan. All rights reserved.
//

#include <iostream>
#include "ListNode.h"
using namespace std;
bool isPalindrome(ListNode* head);

int main(int argc, const char * argv[]) {
    // insert code here...
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new  ListNode(0);
    bool b = isPalindrome(head);
    cout << b << endl;
    return 0;
}
bool isPalindrome(ListNode* head) {
    if(head == NULL || head-> next ==NULL)
        return true;
    if(head->next->next == NULL)
        return (head->val == head->next->val);
    ListNode * l = head;
    ListNode * temp = head;
    ListNode * cur = head;
    ListNode * mid = head;
    int count =0;
    while(l != NULL)
    {
        l = l ->next;
        count ++;
    }
    l = head;
    for(int i = 0; i < count/2 ;  i++)
    {
        temp = l;
        l = l ->next;
    }
    mid = l;
    while(l != NULL)
    {
        cur = l->next;
        l->next = temp;
        temp = l;
        l = cur;
    }
    while(temp!= mid)
    {
        if(head->val != temp->val)
            return false;
        else
        {
            head = head->next;
            temp = temp-> next;
        }
    }
    if(head->val != temp->val)
        return false;
    return true;
}