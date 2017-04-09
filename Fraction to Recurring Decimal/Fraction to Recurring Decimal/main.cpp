//
//  main.cpp
//  Fraction to Recurring Decimal
//
//  Created by Rencheng Tan on 5/5/16.
//  Copyright © 2016 Rencheng Tan. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <stdlib.h>
using namespace std;
string fractionToDecimal(int numerator, int denominator);

int main(int argc, const char * argv[]) {
    // insert code here...
    int a = -1, b = -2147483648;
    cout << -b << endl;
    string c = fractionToDecimal(a,b);
    cout << c << endl;
    return 0;
}


string fractionToDecimal(int numerator, int denominator) {
        long long num = abs(numerator);
        long long denum = abs(denominator);
        string res = "";
        if (num*denum < 0)
            res += "-";
        res += to_string(num/denum);
        
        long long remainder = num % denum;
        if(remainder == 0)
            return res;
        res += ".";
        
        map <int, int> NumToPos;
        string res2 = "";
        int index = 0;
        long long nextRemainder = 0;
        while(remainder != 0)
        {
            remainder *= 10;
            nextRemainder = (remainder%denum);
            if(NumToPos.find(remainder) != NumToPos.end())
            {
                res2.insert(NumToPos.find(remainder)->second, "(");
                res2 += ")";
                return res+res2;
            }
            NumToPos[remainder] = index;
            index++;
            res2 += to_string(remainder/denum);
            remainder = nextRemainder;
        }
        return res+res2;
}