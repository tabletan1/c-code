//
//  ListNode.h
//  Remove Linked List Elements
//
//  Created by Rencheng Tan on 1/7/16.
//  Copyright © 2016 Rencheng Tan. All rights reserved.
//


#ifndef ListNode_h
#define ListNode_h

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

#endif /* ListNode_h */

