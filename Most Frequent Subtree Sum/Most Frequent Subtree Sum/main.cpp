//
//  main.cpp
//  Most Frequent Subtree Sum
//
//  Created by Rencheng Tan on 3/2/17.
//  Copyright © 2017 Rencheng Tan. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;


struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
vector<int> findFrequentTreeSum(TreeNode* root);
int helper(TreeNode* root, int sum, int &max, unordered_map<int, int> &freq);

int main(int argc, const char * argv[]) {
    // insert code here...
    TreeNode * root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->right = new TreeNode(-3);
    vector<int> a = findFrequentTreeSum(root);
    cout << a[0] << endl;
    
    //std::cout << "Hello, World!\n";
    return 0;
}
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> freq;
        //unordered_map
        vector<int> result;
        int max = 0, sum = 0;
        if(!root)
            return result;
        
        helper(root, sum, max, freq);
        for(unordered_map<int, int> :: iterator i = freq.begin(); i != freq.end(); i++)
        {
            if(i->second == max)
                result.push_back(i->first);
        }
        return result;
        
    }
    
    int helper(TreeNode* root, int sum, int &max, unordered_map<int, int> &freq)
    {
        if(!root)
            return 0;
        if(!root->left && !root->right)
        {
            sum = root->val;
            if(freq.find(sum) != freq.end())
                freq[sum]++;
            else
                freq[sum] = 1;
            if(freq[sum] > max)
                max = freq[sum];
            return sum;
        }
        sum += root->val + helper(root->left, sum, max, freq) + helper(root->right, sum, max, freq);
        if(freq.find(sum) != freq.end())
            freq[sum]++;
        else
            freq[sum] = 1;
        if(freq[sum] > max)
            max = freq[sum];
        return sum;
    }
