//
//  main.cpp
//  minimum size subarray sum
//
//  Created by Rencheng Tan on 12/7/15.
//  Copyright © 2015 Rencheng Tan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int minSubArrayLen(int s, vector<int>& nums);
int main() {
    // insert code here...
    vector<int> a = {10,5,13,4,8,4,5,11,14,9,16,10,20,8};
    int n = minSubArrayLen(80, a);
    std::cout << n << endl;
    return 0;
}
    int minSubArrayLen(int s, vector<int>& nums) {
        int full_sum = 0;
        for (unsigned int a = 0; a < nums.size(); a++)
            full_sum = full_sum + nums[a];
        if (nums.size() == 0 || full_sum <s)
            return 0;
        unsigned long int minlen = nums.size(), left = 0, right = 0;
        
        for (;left < nums.size(); left ++ )
        {
            int sum = nums[left];
            right = left;
            while(sum < s && right < (nums.size()-1))
            {
                sum = sum + nums[++right];
            }
            if (sum >= s && minlen > (right-left+1))
            {
                minlen = (right-left+1);
            }
            if (sum < s)
                break;
        }
        return int(minlen);
    }