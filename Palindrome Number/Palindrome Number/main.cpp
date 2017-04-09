//
//  main.cpp
//  Palindrome Number
//
//  Created by Rencheng Tan on 4/11/16.
//  Copyright © 2016 Rencheng Tan. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;
bool isPalindrome(int x);

int main(int argc, const char * argv[]) {
    // insert code here...
    bool a = isPalindrome(1010);
    cout << a << endl;
}
bool isPalindrome(int x) {
    int len = 1, num = 1, n = x;
    while(1)
    {
        n = n / 10;
        if(n == 0)
            break;
        len ++;
    }
    num = pow(10, len-1);
    int right, left;
    while(x > 0)
    {
        right = x / num;
        left = x % 10;
        if(right != left)
            return false;
        else
        {
            x = x % num;
            x = x / 10;
            num = num / 100;
        }
    }
    return true;
}