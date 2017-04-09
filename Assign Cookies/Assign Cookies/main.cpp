//
//  main.cpp
//  Assign Cookies
//
//  Created by Rencheng Tan on 12/21/16.
//  Copyright © 2016 Rencheng Tan. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s);

int main(int argc, const char * argv[]) {
    // insert code here...
    //std::cout << "Hello, World!\n";
        vector<int> a = {10,9,8,7};
        vector<int> b = {5,6,7,8};
    int c = findContentChildren(a, b);
    return 0;
}
int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    if(g.size() == 0 || s.size() == 0)
        return 0;
    int i = 0, j = 0;
    int count = 0;
    while(i < g.size() && j < s.size())
    {
        if(g[i] <= s[j])
        {
            count++;
            i++;
            j++;
        }
        else
            j++;
    }
    return count;
}
