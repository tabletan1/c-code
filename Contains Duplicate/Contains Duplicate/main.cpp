//
//  main.cpp
//  Contains Duplicate
//
//  Created by Rencheng Tan on 11/17/15.
//  Copyright © 2015 Rencheng Tan. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
bool containsDuplicate(vector<int>& );

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> a= {1,2,3,1};
    bool k = containsDuplicate(a);
    if (k == 1)
        cout << "true" << endl;
    else
        cout << "false" << endl;
    return 0;
}

bool containsDuplicate(vector<int>& nums)
{
            vector<int> :: iterator pr;
            for(pr = nums.begin(); pr != nums.end(); pr ++)
            {
                vector<int> :: iterator ph;
                for(ph = pr + 1; ph != nums.end(); ph ++)
                {
                    if (*(ph) == *pr)
                        return true;
                }
            }
            return false;
}
