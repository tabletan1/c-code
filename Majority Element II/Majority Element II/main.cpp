//
//  main.cpp
//  Majority Element II
//
//  Created by Rencheng Tan on 1/3/16.
//  Copyright © 2016 Rencheng Tan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
vector<int> majorityElement(vector<int>& nums);

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> a = {1,2,3};
    vector<int> b = majorityElement(a);
    cout << b[0] << endl;
    return 0;
}
vector<int> majorityElement(vector<int>& nums) {
    if(nums.size()==1)
        return nums;
    vector<int> result={};
    int count = 0;
    for(int i = 0; i < nums.size(); i ++)
    {
        if(find(result.begin(), result.end(), nums[i]) != result.end())
            continue;
        for(int j = i; j < nums.size(); j++)
        {
            if(nums[j]==nums[i])
            {
                count ++;
                //nums.erase (nums.begin()+j);
                //continue;
            }
            if(count > nums.size()/3)
            {
                
                result.push_back(nums[i]);
                break;
            }
        }
        count = 0;
        if(result.size()>=2)
            break;
    }
    return result;
}