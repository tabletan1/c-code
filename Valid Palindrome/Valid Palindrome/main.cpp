//
//  main.cpp
//  Valid Palindrome
//
//  Created by Rencheng Tan on 5/12/16.
//  Copyright © 2016 Rencheng Tan. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;
bool isPalindrome(string s);

int main(int argc, const char * argv[]) {
    // insert code here...
    string a = "1a2";
    bool b =isPalindrome(a);
    
    return 0;
}
bool isPalindrome(string s) {
    if(s == "")
        return true;
    int i = 0, j = s.size()-1;
    string ret1, ret2;
    while(i <= j )
    {
        if((s[i] < 48) || (57 < s[i] && s[i] < 65) || (90 < s[i] && s[i]< 97) || (s[i] > 122))
        {   i++;
            continue;}
        if((s[j] < 48) || (57 < s[j] && s[j] < 65) || (90 < s[j] && s[j]< 97) || (s[j] > 122))
        {   j--;
            continue;}
        if(isalpha(s[i]) && isalpha(s[j]))
        {
            if((s[i] == s[j]+32) || s[i] == s[j] || (s[i]+32 == s[j]))
            {
                i++;
                j--;
                continue;
            }
            else
                return false;
        }
        else
        {
            if(isdigit(s[i]) && isdigit(s[j]))
            {
                if(s[i] == s[j])
                {
                    i++;
                    j--;
                    continue;
                }
                else
                    return false;
            }
            else
                return false;
        }
        
    }
    return true;
}