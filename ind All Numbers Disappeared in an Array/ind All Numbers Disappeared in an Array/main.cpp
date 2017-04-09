//
//  main.cpp
//  ind All Numbers Disappeared in an Array
//
//  Created by Rencheng Tan on 12/21/16.
//  Copyright © 2016 Rencheng Tan. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
vector<int> findDisappearedNumbers(vector<int>& nums);

int main(int argc, const char * argv[]) {
    // insert code here...
    //std::cout << "Hello, World!\n";
    vector<int> a = {4,3,2,7,8,2,3,1};
    vector<int> result = findDisappearedNumbers(a);
    
    return 0;
}

vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int> result;
    if(nums.size() == 0)
        return result;
    for(int i = 0 ; i < nums.size(); i++)
    {
        if(nums[i] == (i+1))
            continue;
        if(nums[nums[i]-1] == nums[i])
            continue;
        else
        {
            swap(nums[i], nums[nums[i]-1]);
            i--;
        }
    }
    for(int i = 0 ; i < nums.size(); i++)
    {
        if(nums[i] != i+1)
            result.push_back(i+1);
    }
    return result;
}
