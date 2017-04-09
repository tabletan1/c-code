//
//  main.cpp
//  Palindrome Partitioning
//
//  Created by Rencheng Tan on 1/11/17.
//  Copyright © 2017 Rencheng Tan. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
bool isPalindrome(const string& s, int start, int end) {
    while(start <= end) {
        if(s[start++] != s[end--])
            return false;
    }
    return true;
}

void dfs(int index, string & s, vector<string> &path, vector<vector<string>> &res)
{
    if(index == s.size())
    {
        res.push_back(path);
        return;
    }
    for(int i = index; i < s.size(); i++)
    {
        if(isPalindrome(s, index, i))
           {
               path.push_back(s.substr(index, i-index+1));
               dfs(i+1, s, path, res);
               path.pop_back();
           }
    }
}
           
vector<vector<string> > partition(string s) {
   vector<vector<string> > res;
   if(s.empty())
       return res;
   vector<string> path;
   dfs(0, s, path, res);
   return res;
}
