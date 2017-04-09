//
//  main.cpp
//  Maximum Product Subarray
//
//  Created by Rencheng Tan on 1/2/16.
//  Copyright © 2016 Rencheng Tan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int maxProduct(vector<int>& nums) ;

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> a = {2,3,-2,-5,4};
    int b =maxProduct(a);
    cout << b << endl;
    return 0;
}
int maxProduct(vector<int>& nums) {
if(nums.size()<=0)
return 0;
if(nums.size()==1)
return nums[0];
int max_val=nums[0], min_val=nums[0], result=nums[0];
for(int i = 1; i< nums.size(); i++)
{
    int temp = min_val *nums[i];
    min_val = min(nums[i], min(temp, max_val*nums[i]));
    max_val = max(nums[i], max(temp, max_val*nums[i]));
    result = max(result, max_val);
}
return result;
}