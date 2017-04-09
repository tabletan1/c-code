//
//  main.cpp
//  Two Sum My Submissions Question Two Sum
//
//  Created by Rencheng Tan on 1/2/16.
//  Copyright © 2016 Rencheng Tan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target);

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums={3,2,4};
    vector<int> b = twoSum(nums, 6);
    cout << b[0]<< b[1] << endl;
    return 0;
}
vector<int> twoSum(vector<int>& nums, int target) {
    sort(nums.begin(),nums.end());
    int left=0;
    int right = nums.size()-1;
    vector<int> result;
    int m =0;
    int n =0;
    while(left < right)
    {
        if(nums[left] + nums[right] == target)
        {
            for(int i = 0; i < nums.size(); i++)
            {
                if(nums[i] == nums[left])
                    m = i;
                if(nums[i] == nums[right])
                    n = i;
            }
            if(m > n)
            {
                result.push_back(n);
                result.push_back(m);
            }
            else
            {
                result.push_back(m);
                result.push_back(n);
            }
        }
        if(nums[left] + nums[right] < target)
            left++;
        if(nums[left] + nums[right] > target)
            right--;
    }
    return result;
}