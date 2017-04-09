//
//  main.cpp
//  trie
//
//  Created by Rencheng Tan on 3/1/17.
//  Copyright © 2017 Rencheng Tan. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;


class Node
{
public:
    char content;
    int count;
    bool isEnd;
    vector<Node*> childList;
    
    
    Node(char c)
    {
        content = c;
        count = 0;
        isEnd = false;
        childList = {NULL};
    }
    
    Node* subNode(char c){
        if(childList.size() != 0){
            for(auto eachChild : childList){
                if(eachChild->content == c){
                    return eachChild;
                }
            }
        }
        return NULL;
    }
};


class Node
{
public:
    char content;
    int count;
    bool isEnd;
    vector<Node*> childList;
    
    
    Node(char c)
    {
        content = c;
        count = 0;
        isEnd = false;
        childList = {NULL};
    }
    
    Node* subNode(char c){
        if(childList.size() != 0){
            for(auto eachChild : childList){
                if(eachChild->content == c){
                    return eachChild;
                }
            }
        }
        return NULL;
    }
};


class Trie {
    
public:
    /** Initialize your data structure here. */
    
    Node *root;
    
    Trie()
    {
        root = new Node(' ');
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        if(search(word) == true) return;
        Node* current = root;
        
        for(int i = 0; i < word.size(); i ++)
        {
            Node *child = current->subNode(word[i]);
            if(child != NULL)
                current = child;
            else
            {
                current->childList.push_back(new Node(word[i]));
                current = current->subNode(word[i]);
            }
            current->count++;
        }
        current->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        //if(!root)
        //  return false;
        Node* current = root;
        for(int i = 0; i < word.size(); i ++)
        {
            Node *child = current->subNode(word[i]);
            if(!child)
                return false;
            else
                current = current->subNode(word[i]);
        }
        if(current->isEnd == false)
            return false;
        else
            return true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        //if(!root)
        //  return false;
        Node* current = root;
        for(int i = 0; i < prefix.size(); i ++)
        {
            Node *child = current->subNode(prefix[i]);
            if(!child)
                return false;
            else
                current = current->subNode(prefix[i]);
        }
        return true;
    }
};



int main(int argc, const char * argv[]) {
    // insert code here...
    Trie a;
    a.insert("a");
    bool b = a.search("a");
    bool c = a.startsWith("a");
    cout << b << c << endl;
    
    return 0;
}

