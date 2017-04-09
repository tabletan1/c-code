//
//  main.cpp
//  Continuous Subarray Sum
//
//  Created by Rencheng Tan on 3/4/17.
//  Copyright © 2017 Rencheng Tan. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
bool checkSubarraySum(vector<int>& nums, int k);
void helper(vector<int>& nums, int k, int &sum, int index, bool &result);

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
bool checkSubarraySum(vector<int>& nums, int k) {
    if(nums.size() == 0 || nums.size() == 1)
        return false;
    if(k == 0)
        return true;
    
    bool result = false ;
    
    for(int i = 0; i < nums.size() - 1; i++)
    {
        int sum = nums[i] + nums[i+1];
        helper(nums, k, sum, i+2,  result);
        if(result == true)
            return result;
    }
    return result;
}

void helper(vector<int>& nums, int k, int &sum, int index, bool &result)
{
    if(sum % k == 0 && sum != 0)
    {
        result = true;
        return;
    }
    if(index >= nums.size())
    return;
    
    sum += nums[index];
    helper(nums, k, sum, index+1, result);
}
