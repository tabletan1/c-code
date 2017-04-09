//
//  main.cpp
//  Count and Say
//
//  Created by Rencheng Tan on 5/22/16.
//  Copyright © 2016 Rencheng Tan. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string countAndSay(int n);


int main(int argc, const char * argv[]) {
    // insert code here...
    string result = countAndSay(4);
    cout << result << endl;
    return 0;
}
string countAndSay(int n) {
    string beg = {"1"};
    if(n == 0)
        return "";
    if(n == 1)
        return beg;
    string ret;
    for(int i = 2; i <= n; i++)
    {
        
        int count = 1;
        ret.clear();
        for(string :: iterator j = beg.begin(); j!= beg.end(); j++)
        {
            
            if(j+1 != beg.end() && *j == *(j+1))
            {
                count ++;
                continue;
            }
            else
            {
                
                string Result;
                ostringstream convert;
                convert << count;
                Result = convert.str();
                ret += Result;
                ret += *j;
                count = 1;
            }
        }
        beg.clear();
        beg = ret;
    }
    return ret;
}