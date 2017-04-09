//
//  main.cpp
//  Binary Tree Inorder Traversal
//
//  Created by Rencheng Tan on 5/5/16.
//  Copyright © 2016 Rencheng Tan. All rights reserved.
//

#include <iostream>
#include <vector>
#include "TreeNode.h"

using namespace std;
void inorderTraversal2(vector<int>& ret, TreeNode* root);
vector<int> inorderTraversal(TreeNode* root);

int main(int argc, const char * argv[]) {
    // insert code here...
    TreeNode a(1);
    vector<int> b = inorderTraversal(&a);
    cout << b[1] << endl;
    return 0;
}
void inorderTraversal2(vector<int>& ret, TreeNode* root)
{
    if (root != NULL)
    {
        inorderTraversal2(ret, root->left);
        ret.push_back(root->val);
        inorderTraversal2(ret, root->right);
    }
}

vector<int> inorderTraversal(TreeNode* root)
{
    
    vector<int> ret;
    inorderTraversal2(ret, root);
    return ret;
}