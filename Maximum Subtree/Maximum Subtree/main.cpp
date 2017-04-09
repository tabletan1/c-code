//
//  main.cpp
//  Maximum Subtree
//
//  Created by Rencheng Tan on 11/18/16.
//  Copyright © 2016 Rencheng Tan. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;



class Node {
public:
    int val;
    vector<Node> children;
    Node(int val){
        this->val = val;
        vector<Node> children;
    }
    Node()
    {}
    
};

class SumCount{
public:
    int sum;
    int count;
    SumCount(int sum, int count){
        this->sum = sum;
        this->count = count;
    }
};


SumCount dfs(Node* root,Node& result);

void getHighAve(Node* root, Node& result);
static double resAve = __DBL_MIN__;


int main(int argc, const char * argv[]) {
    
    // insert code here...
        Node root = Node(1);
        Node a =  Node(2);
        Node b =  Node(3);
        Node c =  Node(4);
        Node d =  Node(5);
        Node e =  Node(5);
        Node f =  Node(5);
        Node g =  Node(5);
        Node h =  Node(5);
        Node i =  Node(5);
        
        a.children.push_back(d);
        a.children.push_back(e);
        b.children.push_back(f);
        b.children.push_back(g);
        
        c.children.push_back(h);
        c.children.push_back(i);
        
        root.children.push_back(a);
        root.children.push_back(b);
        root.children.push_back(c);
        Node result = root;
    
        getHighAve(&root, result);
            cout << result.val << endl;
        return 0;
}
void getHighAve(Node* root, Node& result)
{
    if(root == NULL)
        return;
    SumCount a = dfs(root, result);
    return;
}

SumCount dfs(Node* root, Node& result)
{

    if (root->children.size() == 0){
        SumCount sc =  SumCount(root->val, 1);
        return sc;
    }
    int curSum = root->val;
    int curCnt = 1;
    for(int i = 0; i < root->children.size(); i++)
    {
        SumCount cSC = dfs(&root->children[i], result);
        curSum += cSC.sum;
        curCnt += cSC.count;
    }
    double curAve = (double) curSum/curCnt;
    if (resAve < curAve){
        resAve = curAve;
        result = *root;
    }
    
    return SumCount(curSum,curCnt);
}














