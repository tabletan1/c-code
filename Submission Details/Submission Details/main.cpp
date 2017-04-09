//
//  main.cpp
//  Submission Details
//
//  Created by Rencheng Tan on 12/21/15.
//  Copyright © 2015 Rencheng Tan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int threeSumClosest(vector<int>& nums, int target);

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> a ={1,1,1,1};
    int i = threeSumClosest(a, -100);
    cout << i << endl;
    return 0;
}
int threeSumClosest(vector<int>& nums, int target) {
    if(nums.size()==3)
        return nums[0]+nums[1]+nums[2];
    int left=0, right= nums.size()-1;
    sort(nums.begin(), nums.end());
    int p_max = abs(target)+(nums[0]+nums[1]+nums[2]);
    for(int i = 0; i < nums.size(); i++)
    {
        left = i+1;
        while(left != right && left < right)
        {
            if(nums[left]+nums[right]+nums[i]-target == 0)
                return target;
            if(nums[left]+nums[right]+nums[i]-target > 0)   
            {
                if((nums[left]+nums[right]+nums[i]-target) < abs(p_max))
                    p_max = nums[left]+nums[right]+nums[i]-target;
                right--;
            }
            if(nums[left]+nums[right]+nums[i]-target < 0)
            {
                if(abs(nums[left]+nums[right]+nums[i]-target) < abs(p_max))
                    p_max = nums[left]+nums[right]+nums[i]-target;
                left++;
            }
        }
    }
    return p_max+target;
}