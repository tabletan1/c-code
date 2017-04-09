//
//  main.cpp
//  Maximum Subarray
//
//  Created by Rencheng Tan on 1/2/16.
//  Copyright © 2016 Rencheng Tan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int maxSubArray(vector<int>& nums);

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> a = {-2,1,-3,4,-1,2,1,-5,4};
    int b = maxSubArray(a);
    cout << b << endl;
    return 0;
}
int maxSubArray(vector<int>& nums) {
    int sum = nums[0] , maxSum = nums[0];
    for(int i = 1; i < nums.size(); i++){
        if(sum < 0) sum = 0;   //先判断之前的sum能否被这次利用（小于0则抛弃）
        sum += nums[i];
        maxSum = max(maxSum, sum);
    }
    return maxSum;
    
}