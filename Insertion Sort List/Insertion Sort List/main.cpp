

#include <iostream>
#include "ListNode.h"
using namespace std;
ListNode* insertionSortList(ListNode* head);

int main(int argc, const char * argv[]) {
    // insert code here...
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new  ListNode(4);
    head->next->next->next = new  ListNode(3);
    ListNode* newhead =  insertionSortList(head);
    cout << newhead->next->val << endl;
    return 0;
}
ListNode* insertionSortList(ListNode* head) {
    if(head == NULL || head -> next == NULL)
        return head;
    ListNode * newhead = new ListNode(head->val);
    ListNode * pre = head->next;
    ListNode * cur = head->next;
    ListNode * npre = newhead;
    ListNode * ncur = newhead;
    while(cur)
    {
        if(cur->val <= ncur->val)
        {
            cur = cur -> next;
            pre->next = ncur;
            newhead = pre;
            pre = cur;
            
        }
        else
        {
            while(ncur&& cur->val > ncur->val )
            {
                npre = ncur;
                ncur = ncur->next;
            }
            if(ncur)
            {
                cur = cur->next;
                pre ->next = ncur;
                npre->next = pre;
                pre = cur;
            }
            else
            {
                cur = cur->next;
                npre->next = pre;
                pre->next =NULL;
                pre = cur;
            }
        }
        npre = newhead;
        ncur = newhead;
    }
    return newhead;
}