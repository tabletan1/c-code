//
//  main.cpp
//  majority element
//
//  Created by Rencheng Tan on 11/22/15.
//  Copyright © 2015 Rencheng Tan. All rights reserved.
//

#include <iostream>
#include "vector"
#include <map>
#include <math.h>
using namespace std;
int majorityElement(vector<int>& nums) ;

int main(int argc, const char * argv[]) {
    // insert code here..
    vector<int> a = {3, 2, 3};
    int i = majorityElement(a);
    cout << i << endl;
    return 0;
}
int majorityElement(vector<int>& nums)
{
    sort(nums.begin(), nums.end());
    int k = 0;
    for(int i = 0; i < nums.size(); )
    {
        int count = 1, j = i+1;
        while(nums[j] == nums[i])
        {
            count ++;
            j++;
        }
        i = i + count;
        j --;
        cout << ceil(nums.size()/2 +1) << endl;
        if (count >= ceil(nums.size()/2 +1))
        {
            k = i - 1;
            break;
        }
    }
    return nums[k];
}