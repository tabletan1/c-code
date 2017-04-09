//
//  main.cpp
//  summary range
//
//  Created by Rencheng Tan on 11/20/15.
//  Copyright © 2015 Rencheng Tan. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> summaryRanges(vector<int>& );
string itos (int & );

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> a = {0,1,2,4,5,7};
    vector<string> ss = summaryRanges(a);
    for (vector<string> :: iterator it = ss.begin(); it != ss.end(); it++) {
        cout << *it << endl;
    }
}

vector<string> summaryRanges(vector<int>& nums)
{
    vector<string> range = {} ;
    int c = 0, d = 0;
    while(c < nums.size())
    {
        if((c + 1) < nums.size() && nums[c] + 1 == nums[c + 1])
        {
            c ++;
        }
        else
        {
            if(c == d)
            {
                range.push_back(string("\"") + itos(nums[c]) + string("\""));
                //cout << string("\"") + itos(nums[c]) + string("\"") << endl;
                c ++ ;
                d = c;
            }
            else
            {
                string str =  string("\"") + itos(nums[d]) + "->" + itos(nums[c]) + string("\"") ;
                //cout << str << endl;
                range.push_back(str);
                c ++;
                d = c;
            }
        }
    }
    return range;
}

string itos (int & i)
{
    stringstream ss;
    ss << i;
    string str = ss.str();
    return str;
}