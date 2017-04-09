//
//  main.cpp
//  Longest Palindrome
//
//  Created by Rencheng Tan on 11/1/16.
//  Copyright © 2016 Rencheng Tan. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int longestPalindrome(string s);

int main(int argc, const char * argv[]) {
    // insert code here...
    //std::cout << "Hello, World!\n";
    string s = "abccccdd";
    int a =longestPalindrome(s);
    cout << a << endl;
    return 0;
}

int longestPalindrome(string s) {
    int temp[256] = {0};
    int res = 0;
    int max = 0;
    int flag = 0, hasOdd = 0;
    for(int i = 0; i < s.size(); i++)
    {
        temp[int(s[i])] ++;
    }
    for(int i = 0; i < 256; i++)
    {
        if(temp[i]!= 0 && temp[i]%2 == 0)
        {    res += temp[i];
            if(temp[i] == 1)
                hasOdd = 1;
        }
        else
        {
            if(temp[i] > 2)
            {
                res += (temp[i]);
                flag = 1;
            }
            
        }
    }
    
    if(flag == 1)
        return res;
    else
        return res + hasOdd;
}
