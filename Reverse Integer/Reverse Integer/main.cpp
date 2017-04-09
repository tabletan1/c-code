//
//  main.cpp
//  Reverse Integer
//
//  Created by Rencheng Tan on 4/12/16.
//  Copyright © 2016 Rencheng Tan. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;
int reverse(int x);

int main(int argc, const char * argv[]) {
    // insert code here...
    int i = reverse(1563847412);
    cout << i << endl;
    return 0;
}
int reverse(int x) {
    long long result = 0;
    int len = 0, num = x, p = 0;
    while(num)
    {
        num = num / 10;
        len++;
    }
    for(int i = 0; i < len; i ++)
    {
        int j = x / pow(10, len-1-i), k = pow(10, i);
        int m = pow(10, len-1);
        if(i == (len-1))
        {
            if(result > 2147483647 % m && j >= 2)
                return 0;
            if(result < -2147483648 % m && j <= -2)
                return 0;
        }
        result += j*k;
        p = (pow(10, len-1-i));
        x = x % p;
    }
    
    return result;
}