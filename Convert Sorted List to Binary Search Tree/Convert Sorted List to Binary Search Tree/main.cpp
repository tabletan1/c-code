//
//  main.cpp
//  Convert Sorted List to Binary Search Tree
//
//  Created by Rencheng Tan on 1/28/16.
//  Copyright © 2016 Rencheng Tan. All rights reserved.
//

#include <iostream>
#include "ListNode.h"
#include "TreeNode.h"
using namespace std;
TreeNode* sortedListToBST(ListNode* head);
TreeNode* buildTree(int start, int end, ListNode* &node);

int main(int argc, const char * argv[]) {
    // insert code here...
    ListNode *a = new ListNode(1);
    a->next = new ListNode(2);
    a->next->next = new ListNode(3);
    a->next->next->next = new ListNode(4);
    a->next->next->next->next = new ListNode(5);
    TreeNode* root =  sortedListToBST(a);
    cout << root->val<<endl;
    return 0;
}
TreeNode* sortedListToBST(ListNode* head) {
    int len = 0;
    ListNode * a = head;
    while(a)
    {
        len++;
        a = a->next;
    }
    return buildTree(0, len-1, head);
}
TreeNode* buildTree(int start, int end, ListNode* &node){
    if(start > end)
        return NULL;
    int mid = (start + (end-start))/2;
    TreeNode *left = buildTree(start, mid-1, node);
    TreeNode* root = new TreeNode(node->val);
    root->left = left;
    node = node->next;
    root->right = buildTree(mid+1, end, node);
    return root;
}