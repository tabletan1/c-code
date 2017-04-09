//
//  main.cpp
//  Max Consecutive Ones
//
//  Created by Rencheng Tan on 2/20/17.
//  Copyright © 2017 Rencheng Tan. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums);

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> a = {1,0,1,1,0,1};
    int b =findMaxConsecutiveOnes(a);
    //std::cout << "Hello, World!\n";
    return 0;
}

int findMaxConsecutiveOnes(vector<int>& nums) {
    int count = 0, result = 0;
    if(nums.size() == 0)
        return count;
    
    for(int i = 0; i < nums.size(); i++)
    {
        if((i-1)>=0 && nums[i-1] == 0 && nums[i] == 1)
        {
            count = 1;
            if(count > result)
                result = count;
            continue;
        }
        if(i == 0 && nums[i] ==1)
        {
            count = 1;
            if(count > result)
                result = count;
            continue;
        }
        if((i-1)>=0 && nums[i-1] == 1 && nums[i] ==1)
        {
            count ++;
            if(count > result)
                result = count;
            continue;
        }
        count = 0;
    }    return result;
}
