//
//  TreeNode .h
//  Convert Sorted List to Binary Search Tree
//
//  Created by Rencheng Tan on 1/28/16.
//  Copyright © 2016 Rencheng Tan. All rights reserved.
//

#ifndef TreeNode__h
#define TreeNode__h

struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode(int x) : val(x), left(NULL), right(NULL) {}
     };
#endif /* TreeNode__h */
