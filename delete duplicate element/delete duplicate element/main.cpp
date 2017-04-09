//
//  main.cpp
//  delete duplicate element
//
//  Created by Rencheng Tan on 11/20/15.
//  Copyright © 2015 Rencheng Tan. All rights reserved.
//

#include <iostream>
#include "vector"
using namespace std;

int removeDuplicates(vector<int> & );



int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> a = {1,1};
    int i = 0;
    i = removeDuplicates(a);
    return 0;
}

int removeDuplicates(vector<int>& nums) {
    if (nums.size() == 0 || nums.size() == 1)
        return nums.size();
   // signed int count = 0;
    for(vector<int> :: iterator iter = nums.begin(); iter != nums.end()-1; iter ++)
    {
        if (*iter == *(iter + 1))
        {
     //       count ++;
            nums.erase(iter);
            iter --;
        }
    }
    return nums.size();
}