//
//  main.cpp
//  First Unique Character in a String
//
//  Created by Rencheng Tan on 2/25/17.
//  Copyright © 2017 Rencheng Tan. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;
int firstUniqChar(string s);

int main(int argc, const char * argv[]) {
    // insert code here...
    string s = "leetcode";
    int b = firstUniqChar(s);
    
    std::cout << b << endl;
    return 0;
}
int firstUniqChar(string s) {
    if(s == "")
        return -1;
    vector<int> a(0, 256);
    
    for(int i = 0; i < s.size(); i++)
        a[s[i]]++;
    
    for(int i = 0; i < s.size(); i++)
        if(a[s[i]] == 1)
            return i;
    return -1;
    
}
