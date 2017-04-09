//
//  main.cpp
//  Product of Array Except Self
//
//  Created by Rencheng Tan on 12/17/15.
//  Copyright © 2015 Rencheng Tan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums);

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> a = {9,0,-2};
    vector<int> b = productExceptSelf(a);
    std::cout << b[0] << b[1] << b[2] << endl;
    return 0;
}

    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size(), 0);
        int sum_right = 1;
        for(int i = nums.size()-1; i >=0 ; i --)
        {
            sum_right = sum_right * nums[i];
            result[i] = sum_right;
        }
        int sum_left = 1;
        result[0] = result[1];
        for(int j = 1; j < nums.size(); j ++)
        {
            sum_left = sum_left * nums[j-1];
            if(j+1 <= nums.size()-1)
                result[j] = sum_left * result[j + 1];
            else
                result[j] = sum_left;
            
        }
        return result;
    }
