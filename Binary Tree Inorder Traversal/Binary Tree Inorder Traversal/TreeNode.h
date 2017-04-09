//
//  TreeNode.h
//  Binary Tree Inorder Traversal
//
//  Created by Rencheng Tan on 5/5/16.
//  Copyright © 2016 Rencheng Tan. All rights reserved.
//

#ifndef TreeNode_h
#define TreeNode_h
struct TreeNode {
        int val;
         TreeNode *left;
        TreeNode *right;
         TreeNode(int x) : val(x), left(NULL), right(NULL) {}
     };

#endif /* TreeNode_h */
