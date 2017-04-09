//
//  ListNode.h
//  Palindrome Linked List
//
//  Created by Rencheng Tan on 1/6/16.
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
