//
//  main.cpp
//  Repeated Substring Pattern
//
//  Created by Rencheng Tan on 2/2/17.
//  Copyright © 2017 Rencheng Tan. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

bool repeatedSubstringPattern(string str);


int main(int argc, const char * argv[]) {
    // insert code here...
    string a = "abaababaab";
    bool b = repeatedSubstringPattern(a);
    cout << b << endl;
    return 0;
}

bool repeatedSubstringPattern(string str) {
    if (str == "")
        return true;
    
    int i = 0, j = 1;
    int index = 0;
    while(j != str.size())
    {
        int flag = 1;
        
        while(str[i] == str[j])
        {
            if(flag)
            {
                index = j;
                flag = 0;
            }
            j++;
            i++;
            if(i < str.size() && j < str.size() && str[i] != str[j])
            {
                flag = 1;
                i = 0;
                j = index+1;
            }
        }
        if(j < str.size() && str[i] != str[j])
            j++;
    }
    
    
    if(i == 0)
        return false;
    
    string pat = str.substr(i);
    for(int k = 0; k < str.size(); k+=pat.size())
    {
        if(str.substr(k, pat.size()) == pat)
            continue;
        else
            return false;
    }
    return true;
    
}
